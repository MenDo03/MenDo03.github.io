# Active Directory Home Lab

A personal home lab project simulating a real enterprise Active Directory environment from scratch using virtual machines. Built for hands-on learning, portfolio documentation, and practical experience with systems administration and IT helpdesk workflows.

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

### 📁 [User Management & Domain Integration](./User%20Management%20%26%20Domain%20Integration)
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

## Key Things Learned

- How Active Directory works as a centralized identity and access management system
- The difference between local machine accounts and domain accounts
- How DNS, static IPs, and network adapters work together in a domain environment
- Real helpdesk workflows and the security practices that go with them
- Why do certain things like account lockout policies only work at the domain level
- Proper procedures around account management — when to act and when to check with HR first

---

## More Coming Soon

This lab is still actively being built. Planned additions include:

- Group Policy Objects (GPOs) — password policy, control panel restrictions, desktop wallpaper enforcement
- Shared Network Folder with Permissions — NTFS and share permissions per group
- Account Lockout Policy — triggering and unlocking accounts
- DHCP Setup — automatic IP assignment for client machines
- Mapped Network Drive via GPO — automatically mapping drives on user login

---

> This lab was built from scratch as a self-study project with no prior work experience in IT infrastructure. Everything documented here was learned, broken, fixed, and documented hands-on.
