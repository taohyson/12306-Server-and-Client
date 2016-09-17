#include "abstractuser.h"

AbstractUser::AbstractUser(QString newUsername,QString newPassword, QString newName, QString newPhone, bool newIsAdmin)
	:username(newUsername),password(newPassword),name(newName),phone(newPhone),isAdmin(newIsAdmin){}

