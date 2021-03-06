/**
 * e8yes demo web.
 *
 * <p>Copyright (C) 2020 Chifeng Wen {daviesx66@gmail.com}
 *
 * <p>This program is free software: you can redistribute it and/or modify it under the terms of the
 * GNU General Public License as published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * <p>This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * <p>You should have received a copy of the GNU General Public License along with this program. If
 * not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SYNC_NODE_STATE_H
#define SYNC_NODE_STATE_H

#include "distributor/mutation_propagator/propagator.h"
#include "distributor/store/node_state_store.h"
#include "distributor/store/peer_store.h"
#include "proto_cc/node.pb.h"

namespace e8 {

/**
 * @brief SyncNodeStates Applies the node states snapshot difference between the current node and
 * the peer nodes to the peer nodes, if there is any.
 *
 * @return True if no error occurs, otherwise false.
 */
bool SyncNodeStates(PeerStoreInterface *peers, NodeStateStoreInterface *node_states,
                    PropagatorInterface *propagator);

} // namespace e8

#endif // SYNC_NODE_STATE_H
