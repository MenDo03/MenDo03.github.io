# Active Directory Home Lab — Group Policy Objects (GPO)

A continuation of the Active Directory Home Lab series. This section covers configuring Group Policy Objects to enforce security settings and control the user environment across the domain — all from one place without touching each machine individually.

---

## Environment

| Component | Details |
|---|---|
| Platform | Oracle VirtualBox |
| Domain Controller | Windows Server 2022 |
| Client Machine | Windows 11 |
| Domain Name | LAB.local |

---

## What This Covers

- Account Lockout Policy — locks accounts after failed login attempts
- Password Complexity Policy — enforces minimum password standards
- Prohibit Access to Control Panel — restricts users from changing system settings
- Desktop Wallpaper Enforcement — forces a specific wallpaper on all user machines

---

## Key Concept — Computer vs User Configuration

Every GPO has two sections:

- **Computer Configuration** — applies to the machine regardless of who is logged in. Takes effect on startup.
- **User Configuration** — applies to the user regardless of which machine they log into. Takes effect on login.

> **Note:** Account and password policies always go under Computer Configuration. Control Panel and wallpaper restrictions go under User Configuration.

---

## GPO 1 — Account Lockout Policy

Locks a user's account after a set number of failed login attempts. Protects against brute force attacks where someone repeatedly guesses passwords.

**Path:**
```
Computer Configuration > Policies > Windows Settings > Security Settings > Account Policies > Account Lockout Policy
```

**Settings Applied:**
- Lockout Threshold: **3 invalid attempts**
- Lockout Duration: **0** — admin must manually unlock
- Reset Counter After: **3 minutes**

![Account Lockout Policy](screenshots/account-lockout-policy.png)

> **Note:** Domain admin accounts are exempt from lockout by default. Always test with a regular domain user like `LAB\BCampbell`.

---

## GPO 2 — Password Complexity Policy

Enforces minimum standards for user passwords. Weak passwords are one of the most common entry points for attackers.

**Path:**
```
Computer Configuration > Policies > Windows Settings > Security Settings > Account Policies > Password Policy
```

**Settings Applied:**
- Minimum Password Length: **8 characters**
- Password Must Meet Complexity Requirements: **Enabled**

![Password Complexity Policy](screenshots/password-complexity-policy.png)

---

## GPO 3 — Prohibit Access to Control Panel

Prevents regular users from opening Control Panel or PC Settings.

**Why this matters:**
- Stops users from accidentally changing network settings that could disconnect them from the domain
- Prevents unauthorized software installs or removals
- Keeps the environment consistent and easier to manage from the admin side

**Path:**
```
User Configuration > Policies > Administrative Templates > Control Panel
```

Setting: **Prohibit access to Control Panel and PC Settings** → Enabled

![Control Panel Restriction](screenshots/control-panel-restriction.png)

---

## GPO 4 — Desktop Wallpaper Enforcement

Forces a specific desktop wallpaper on all user machines and prevents users from changing it.

**Why this matters:**
- Companies use wallpapers to display security notices or acceptable use policy reminders
- Keeps the visual environment consistent across all company machines
- In high-security environments, wallpapers can display data classification labels or handling reminders

**Path:**
```
User Configuration > Policies > Administrative Templates > Desktop > Desktop > Desktop Wallpaper
```

Setting: **Desktop Wallpaper** → Enabled → enter local wallpaper path

![Desktop Wallpaper GPO](screenshots/desktop-wallpaper-gpo.png)

---

## Applying and Verifying GPOs

After making changes, force the policy update on the Windows 11 client:

```
gpupdate /force
```

To verify which GPOs are currently applied:

```
gpresult /r
```

> **Note:** Some Computer Configuration policies require a full restart to take effect — if a policy isn't applying after `gpupdate /force`, restart the client VM and test again.

---

## Key Takeaways

- GPOs are applied by location — where you link them determines who they affect
- Account and password policies must be linked at the domain level, not a specific OU
- Knowing the difference between Computer Configuration and User Configuration is essential
- `gpupdate /force` is the first thing to run when testing any GPO change
- Domain admins are always exempt from lockout policies — test with regular user accounts
- GPOs are one of the most common topics in IT interviews — being able to walk through a configuration is a big advantage

---

## Related

- [Part 1 — Setup & Configuration](../Setup%20&%20Configuration/README.md)
- [Part 2 — User Management & Domain Integration](../User%20Management%20&%20Domain%20Integration/README.md)
- [Part 3 — Forgot Password](../Forgot%20Password/README.md)
- [Part 4 — Basic IT Ticketing](../Basic%20IT%20Ticketing/README.md)
