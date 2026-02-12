# CINF301 — Team Project

A static website built as a team assignment for CINF301. It demonstrates responsive layout, semantic vs. div-only markup, and Git workflow (PRs, approvals).

## Requirements

- **first-page:** Uses semantic HTML (header, nav, main, section, article, aside, footer, table). Responsive on screens &lt; 768px.
- **second-page:** Same content and layout using **only `<div>`** elements (no semantic tags, no `<table>`). Responsive to match first-page mobile behavior.
- **Git rules:** No direct commits to `main`. All changes via pull requests; 2 approvals required before merge.

## Contents

| Folder     | Description |
| ---------- | ----------- |
| `first-page/` | Semantic markup, `index.html` + `css/styles.css`. Links to second-page. |
| `second-page/` | Div-only recreation, same structure. Links back to first-page. |

## How to run locally

No build tools needed. Open the HTML files in a browser, or use a local server:

```bash
cd cinf301-spr26-g3boys
python3 -m http.server 8000
# Open http://localhost:8000/first-page/ or http://localhost:8000/second-page/
```

## Team

Temirlan, Mohammed, Michael
