# Active Directory Home Lab

A personal hands-on Active Directory home lab simulating a small enterprise environment using Windows Server 2022, and Windows 11 viritual machines. Built to develop practical experience in Windows Server administration, Active Directory Domain Services, and common IT support workflows while documenting each stage of deployment and configuration.

---

## Environment

| Component | Details |
|---|---|
| Platform | Oracle VirtualBox |
| Domain Controller | Windows Server 2022 |
| Client Machine | Windows 11 |
| Domain Name | LAB.local |

---

## What This Lab Covers

This repo is broken down into separate sections, each focusing on a different part of the Active Directory environment. More sections will be added as the lab continues to grow.

---

### 📁 [Setup & Configuration](./Setup%20&%20Configuration)
Getting the environment up and running from scratch.
- Provisioned two VMs in VirtualBox — Windows Server 2022 and Windows 11
- Renamed the server and configured network adapters
- Assigned a static IP address to the Domain Controller
- Installed Active Directory Domain Services (AD DS)
- Promoted the server to a Domain Controller and created a new forest (LAB.local)

---

### 📁 [User Management & Domain Integration](./User%20Management%20&%20Domain%20Integration)
Managing users, groups, and connecting client machines to the domain.
- Created Organizational Units (OUs) to organize users and groups
- Added user accounts and security groups
- Pointed the Windows 11 client DNS to the Domain Controller
- Joined the Windows 11 machine to the LAB.local domain
- Logged in as a domain user from the client machine

---

### 📁 [Forgot Password](./Forgot%20Password)
A real troubleshooting scenario — recovering access to a disabled local account.
- Attempted to reset local account from the server (and learned why that doesn't work)
- Used domain admin credentials to elevate CMD privileges on the client machine
- Reset the local account password via Command Prompt
- Discovered and resolved the default disabled state of the built-in Windows 11 Administrator account

---

### 📁 [Basic IT Ticketing](./Basic%20IT%20Ticketing)
Simulating common helpdesk tickets using the lab environment.
- Password reset with forced change on next logon
- Unlocking a locked-out account
- Disabling and re-enabling user accounts following proper HR procedures
- Understanding password and contractor account expiration policies

---

### 📁 [Group Policy Project](./Adding%20GPO)
Configuring Group Policy Objects to enforce security settings and control the user environment across the domain.
- Created and linked GPOs at both the domain and OU level
- Configured Account Lockout Policy — locks accounts after 3 failed attempts, admin unlock required
- Configured Password Complexity Policy — minimum length and complexity requirements
- Restricted access to the Control Panel for regular users
- Enforced a desktop wallpaper across all user machines
- Used gpupdate /force and gpresult /r to apply and verify policies

---

### 📁 [Shared Folder Permissions & Network Mapped Drive](./Shared%20Folder%20Permissions%20&%20Network%20Mapped%20Drive)
Setting up shared folders, configuring permissions per group, and mapping network drives manually and through GPO.
- Added a user to the correct Active Directory group
- Created a shared folder structure on the server
- Configured Share Permissions and NTFS Permissions
- Verified folder access on the client machine
- Manually mapped a network drive on the client
- Automated drive mapping via GPO with Item-Level Targeting so drives only appear for the correct group
- Removed user access by removing them from the group

---

## Key Things Learned

- How Active Directory works as a centralized identity and access management system
- The difference between local machine accounts and domain accounts
- How DNS, static IPs, and network adapters work together in a domain environment
- Real helpdesk workflows and the security practices that go with them
- Why certain policies like Account Lockout only work when applied at the domain level
- Proper procedures around account management — when to act and when to check with HR first
- How GPOs work and the difference between Computer Configuration and User Configuration
- The two layers of folder permissions — Share Permissions and NTFS Permissions
- Why permissions should always be assigned to groups, never individual users
- How Item-Level Targeting makes GPO drive mapping smart and group-specific

---

## More Coming Soon

This lab is still actively being built. Planned additions include:

- DHCP Setup — automatic IP assignment for client machines

---

> This lab was built from scratch as a self-study project with no prior work experience in IT infrastructure. Everything documented here was learned, broken, fixed, and documented hands-on.
