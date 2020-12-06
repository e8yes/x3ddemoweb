import 'package:demoweb_app/src/connection_manager_interface.dart';
import 'package:demoweb_app/src/credential_storage.dart';
import 'package:demoweb_app/src/grpc_requester.dart';
import 'package:demoweb_app/src/identity_storage.dart';
import 'package:demoweb_app/src/immediate_connection.dart';

Uri demowebServiceUri = Uri.parse("http://home.e8yes.org:18000");
// Uri demowebServiceUri = Uri.parse("http://192.168.30.202");

ConnectionManagerInterface demowebServiceConnections =
    ImmediateConnection(demowebServiceUri);
GrpcRequester demowebServiceRequester =
    GrpcRequester(demowebServiceConnections);

IdentityStorage identityStorage = IdentityStorage();
CredentialStorage credentialStorage = CredentialStorage();

const int kSecurityKeyLength = 128;

const String kIdPathVariable = "id";
