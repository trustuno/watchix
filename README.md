![Build Status](https://github.com/trustuno/watchix/actions/workflows/build.yml/badge.svg)


<h1 align="center">WatchiX Agent</h1>
<p align="center">
🛡️ Lightweight observability for embedded systems • 🌐 Open Source
</p>

---

WatchiX is a powerful, scalable, and cross-platform **certificate lifecycle monitoring and management agent**.  
It provides a comprehensive solution for **certificate expiry monitoring**, **notifications**,  **renew**, **secure agent-cloud communication**, and **optional on-premises management**.

---

## 🚀 What is WatchiX?

In today's digital landscape, managing SSL/TLS X.509 certificates is critical to maintaining security, trust, and uptime.  
WatchiX simplifies this with an agent-based solution that can:

- Monitor certificates on servers, network devices, and applications.
- Send proactive expiry notifications.
- Facilitate auto-renewals and revocations.
- Securely communicate with the cloud or run fully on-premises.

---

## 🔍 Key Features

### Near-Term Features (v1.x) ![Before: Jan 2026](https://img.shields.io/badge/Before-Jan_2026-dark_green)
- ✅ Certificate expiry monitoring.
- ✅ Daily checks and real-time status reporting.
- ✅ Chain of trust verification.
- ✅ Configurable notifications (email, Slack, Telegram).
- ✅ Cloud agent communication with mutual TLS (mTLS).
- ✅ On-premises deployment option (no cloud dependency).
- ✅ Docker-compatible build and deployment.

### Mid-Term Features (v2.x)  ![Before: Jun 2026](https://img.shields.io/badge/Before-Jun_2026-dark_green)
- 🔄 Cloud-based dashboard for multi-agent management.
- 🔄 IPsec-based secure communication option.
- 🔄 Certificate auto-renewal via integrated CA APIs
- 🔄 Revocation handling from the cloud.
- 🔄 Role-based access control (RBAC) for agents and cloud UI.
- 🔐 API Integration of : ![Planned: DigiCert](https://img.shields.io/badge/DigiCert-planned-blue)  ![Planned: GlobalSign](https://img.shields.io/badge/GlobalSign-planned-blue) ![Planned: Let's Encrypt](https://img.shields.io/badge/LetsEncrypt-planned-blue) ![Planned: Sectigo](https://img.shields.io/badge/Sectigo-planned-blue)

### Long-Term Vision (v3.x) ![Before: Dec 2026](https://img.shields.io/badge/Before-Dec_2026-dark_green)
- 🌐 On-premises edge server for full private deployments.
- 🌐 Embedded CMP (Certificate Management Protocol) server integration.
- 🌐 SLA-backed premium support.
- 🌐 Integration with enterprise-grade PKI providers.

---

## 🔒 Security Commitment

WatchiX is designed with security-first principles:
- Mutual TLS for agent-cloud communication.
- Option for fully private on-premises operation.
- Plans for signed and verified agent binaries.
- No unnecessary data sharing.
---

🤝 How to Contribute
We welcome contributions from developers, testers, and security experts.

Contribution Steps:
- Fork this repository.
- Create a new branch: git checkout -b feature/your-feature-name
- Make your changes.
- Submit a pull request (PR) with detailed description.

Areas You Can Contribute:
- New notification plugins (e.g., WhatsApp, MS Teams).
- Cloud dashboard UI.
- Security hardening.
- Testing frameworks.
- Documentation improvements.

Note:
Ensure your code is well-documented.
Follow the existing directory and build structure.
