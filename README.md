![Build Status](https://github.com/trustuno/watchix/actions/workflows/build.yml/badge.svg)


<h1 align="center">WatchiX Agent</h1>

<p align="center">
  Lightweight • Secure • Scalable • Open Source • Cross Platform
</p>

---

WatchiX is a powerful, scalable, and cross-platform **certificate lifecycle monitoring and management agent**.  
It provides a comprehensive solution for **certificate expiry monitoring**, **notifications**, **renewals**, **secure agent-cloud communication**, and **optional on-premises management**.

---

## 🚀 What is WatchiX?

In today's digital landscape, managing SSL/TLS X.509 certificates is critical for maintaining security, trust, and uptime.  
**WatchiX simplifies this** with an agent-based solution that can:

- 🕒 Monitor certificates on servers, network devices, and applications.
- 🚨 Send proactive expiry notifications.
- 🔄 Facilitate auto-renewals and revocations.
- 🔐 Securely communicate with the cloud or run fully on-premises.

---

## 🔍 Key Features

### 🎯 Near-Term Features (v1.x)  
![Planned: Before Jan 2026](https://img.shields.io/badge/Target-Jan_2026-dark_green)
- ✅ Certificate expiry monitoring.
- ✅ Daily checks and real-time status reporting.
- ✅ Chain of trust verification.
- ✅ Configurable notifications (Email, Slack, Telegram).
- ✅ Cloud agent communication with mutual TLS (mTLS).
- ✅ Fully on-premises deployment option (no cloud dependency).
- ✅ Docker-compatible build and deployment.

### 🛠️ Mid-Term Features (v2.x)  
![Planned: Before Jun 2026](https://img.shields.io/badge/Target-Jun_2026-dark_green)
- 🔄 Cloud-based dashboard for multi-agent management.
- 🔄 IPsec-based secure communication option.
- 🔄 Certificate auto-renewal via integrated CA APIs.
- 🔄 Revocation handling from the cloud.
- 🔄 Role-based access control (RBAC) for agents and cloud UI.
- 🔄 Planned integrations:
    - ![Planned: DigiCert](https://img.shields.io/badge/DigiCert-planned-lightgrey)
    - ![Planned: GlobalSign](https://img.shields.io/badge/GlobalSign-planned-lightgrey)
    - ![Planned: Let's Encrypt](https://img.shields.io/badge/LetsEncrypt-planned-lightgrey)
    - ![Planned: Sectigo](https://img.shields.io/badge/Sectigo-planned-lightgrey)

### 🌐 Long-Term Vision (v3.x)  
![Planned: Before Dec 2026](https://img.shields.io/badge/Target-Dec_2026-dark_green)
- 🌐 On-premises edge server for full private deployments.
- 🌐 Embedded CMP (Certificate Management Protocol) server integration.
- 🌐 SLA-backed premium support.
- 🌐 Integration with enterprise-grade PKI providers.

---

## 🔒 Security Commitment

WatchiX is designed with **security-first principles:**
- ✅ Mutual TLS for agent-cloud communication.
- ✅ Option for fully private on-premises operation.
- ✅ Plans for signed and verified agent binaries.
- ✅ No unnecessary data sharing or telemetry.

---

## 🤝 How to Contribute

We welcome contributions from **developers, testers, and security experts.**

### Contribution Steps:
1. Fork this repository.
2. Create a new branch: `git checkout -b feature/your-feature-name`
3. Make your changes.
4. Submit a pull request (PR) with a detailed description.

### Areas You Can Contribute:
- 📢 New notification plugins (e.g., WhatsApp, MS Teams).
- 🖥️ Cloud dashboard UI.
- 🔒 Security hardening.
- 🧪 Testing frameworks.
- 📚 Documentation improvements.

> **Note:**  
> Please ensure your code is well-documented and follows the existing directory and build structure.

---

## 📫 Stay Connected
- 🌐 GitHub: [Watchix Agent](https://github.com/trustuno/watchix)
- 📄 Documentation: [Watchix Docs](https://trustuno.github.io/watchix-docs/)
