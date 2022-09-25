class ConsistentHashingWithTokens:
    def __init__(
            self,
            server_tokens: Dict[ServerId, int],
            seed: int = SEED,
    ):
        assert all(tokens >= 1 for tokens in server_tokens.values())
        self._seed = seed
        self._server_tokens = server_tokens
        self._update_token_hashes()

    def _update_token_hashes(self):
        self._server_allocations = {
            (server_id, token_idx): ServerToken(
                server_id=server_id,
                token_idx=token_idx, _seed=self._seed,
            )
            for server_id, token_count in self._server_tokens.items()
            for token_idx in range(token_count)
        }

    @classmethod
    def equal_tokens(
            cls,
            servers: Set[ServerId],
            tokens: int = 1,
            seed: int = SEED,
    ) -> "ConsistentHashingWithTokens":
        return cls(
            server_tokens={server: tokens for server in servers},
            seed=seed,
        )

    def key_lookup(self, key: str) -> ServerToken:
        key_hash = ServerToken(
            server_id=key,
            token_idx=0,  # dummy value
            _seed=self._seed,
        ).hash_value
        distances = (
            (key_hash - server_token_obj.hash_value, server_id)
            for (server_id, _), server_token_obj
            in self._server_allocations.items()
        )
        return self._find_closest(distances=distances)

    def _find_closest(
        self,
        distances: Iterable[Tuple[int, ServerId]],
    ) -> ServerId:
        # find the server with the smallest positive distance
        # assign None if no such server exists
        # which means that the server with the largest hash is
        # responsible for this key
        closest = min((
            (dist, server_id)
            for dist, server_id in distances
            if dist >= 0
        ), default=None)
        return (
            # get the ID of the server with the largest hash value
            max(self._server_allocations.values()).server_id
            if closest is None
            else closest[1]
        )

    def _add_server_tokens(self, server_id: ServerId, token_count: int) -> None:
        for token_idx in range(token_count):
            self._server_allocations[(server_id, token_idx)] = ServerToken(
                server_id=server_id,
                token_idx=token_idx,
                _seed=self._seed,
            )

    def _remove_server_tokens(self, server_id: ServerId) -> None:
        for token_idx in range(self._server_tokens[server_id]):
            del self._server_allocations[(server_id, token_idx)]
        del self._server_tokens[server_id]

    def add_server(self, server_id: ServerId, token_count: int = 1) -> None:
        if token_count < 1:
            raise ValueError(f"make sure that token_count >= 1")
        if (server_id, 0) in self._server_allocations:
            raise ValueError(f"server_id={server_id} already exist. use `update_server` instead.")
        self._add_server_tokens(server_id=server_id, token_count=token_count)
        self._server_tokens[server_id] = token_count

    def update_server(
            self,
            server_id: ServerId,
            token_count: int,
    ) -> None:
        if token_count < 1:
            raise ValueError(
                f"make sure that token_count >= 1"
            )
        self._remove_server_tokens(
            server_id=server_id
        )
        self._add_server_tokens(
            server_id=server_id,
            token_count=token_count,
        )
        self._server_tokens[server_id] = token_count

    def remove_server(self, server_id: str) -> None:
        if (server_id, 0) in self._server_allocations:
            if len(self._server_tokens) == 1:
                raise ValueError("only one server is left, cannot delete")
            self._remove_server_tokens(server_id=server_id)
        else:
            raise ValueError(f"server ID {server_id} does not exist")
