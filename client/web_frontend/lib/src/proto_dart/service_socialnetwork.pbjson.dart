///
//  Generated code. Do not modify.
//  source: service_socialnetwork.proto
//
// @dart = 2.3
// ignore_for_file: camel_case_types,non_constant_identifier_names,library_prefixes,unused_import,unused_shown_name,return_of_invalid_type

const GetUserRelationsRequest$json = const {
  '1': 'GetUserRelationsRequest',
  '2': const [
    const {'1': 'target_user_id', '3': 1, '4': 1, '5': 3, '10': 'targetUserId'},
  ],
};

const GetUserRelationsResponse$json = const {
  '1': 'GetUserRelationsResponse',
  '2': const [
    const {'1': 'source_user_id', '3': 1, '4': 1, '5': 3, '10': 'sourceUserId'},
    const {'1': 'target_user_id', '3': 2, '4': 1, '5': 3, '10': 'targetUserId'},
    const {'1': 'user_relations', '3': 3, '4': 3, '5': 11, '6': '.e8.UserRelationRecord', '10': 'userRelations'},
  ],
};

const SendInvitationRequest$json = const {
  '1': 'SendInvitationRequest',
  '2': const [
    const {'1': 'invitee_user_id', '3': 1, '4': 1, '5': 3, '10': 'inviteeUserId'},
  ],
};

const SendInvitationResponse$json = const {
  '1': 'SendInvitationResponse',
};

const DeleteInvitationRequest$json = const {
  '1': 'DeleteInvitationRequest',
  '2': const [
    const {'1': 'invitee_user_id', '3': 1, '4': 1, '5': 3, '10': 'inviteeUserId'},
  ],
};

const DeleteInvitationResponse$json = const {
  '1': 'DeleteInvitationResponse',
};

const ProcessInvitationRequest$json = const {
  '1': 'ProcessInvitationRequest',
  '2': const [
    const {'1': 'inviter_user_id', '3': 1, '4': 1, '5': 3, '10': 'inviterUserId'},
    const {'1': 'accept', '3': 2, '4': 1, '5': 8, '10': 'accept'},
  ],
};

const ProcessInvitationResponse$json = const {
  '1': 'ProcessInvitationResponse',
};

const DeleteContactRequest$json = const {
  '1': 'DeleteContactRequest',
  '2': const [
    const {'1': 'deleted_contact_user_id', '3': 1, '4': 1, '5': 3, '10': 'deletedContactUserId'},
  ],
};

const DeleteContactResponse$json = const {
  '1': 'DeleteContactResponse',
  '2': const [
    const {'1': 'deleted', '3': 1, '4': 1, '5': 8, '10': 'deleted'},
  ],
};

const SearchRelatedUserListRequest$json = const {
  '1': 'SearchRelatedUserListRequest',
  '2': const [
    const {'1': 'search_terms', '3': 1, '4': 1, '5': 9, '10': 'searchTerms'},
    const {'1': 'pagination', '3': 2, '4': 1, '5': 11, '6': '.e8.Pagination', '10': 'pagination'},
    const {'1': 'relation_filter', '3': 3, '4': 3, '5': 14, '6': '.e8.UserRelation', '10': 'relationFilter'},
  ],
};

const SearchRelatedUserListResponse$json = const {
  '1': 'SearchRelatedUserListResponse',
  '2': const [
    const {'1': 'user_profiles', '3': 1, '4': 3, '5': 11, '6': '.e8.UserPublicProfile', '10': 'userProfiles'},
  ],
};

