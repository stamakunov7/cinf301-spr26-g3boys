# CINF301 — Team Project

This repository contains a small static website built as a team assignment for CINF301. It demonstrates a simple, responsive layout with two pages:

- `first-page/` — the original page using semantic HTML elements (header, nav, main, section, article, aside, footer, table).
- `second-page/` — a recreation of the first page that uses only `<div>` elements for structure (no semantic structural tags or `<table>`). The goal is to match the visual layout while using only `div`s and CSS for structure.

Contents
--------

- `first-page/`
	- `index.html` — semantic markup and layout.
	- `css/styles.css` — styles for the semantic page.

- `second-page/`
	- `index.html` — div-only markup that visually reproduces the first page.
	- `css/styles.css` — styles adapted from the first page but targeting the div-based classes.

How it differs
---------------

The `first-page` uses semantic HTML elements (recommended for accessibility and document structure). The `second-page` intentionally avoids those semantic tags and instead implements the same sections using only `<div>` elements styled with CSS. This is an exercise in layout and CSS selectors.

Run locally
-----------

This is a static site — no build tools or server are required. To view the pages locally open the HTML files in your browser.

From the repository root (macOS / zsh):

```bash
# open the first page in the default browser
open first-page/index.html

# open the second page (div-only version)
open second-page/index.html
```

Alternatively, you can start a small local HTTP server (recommended when testing fonts/CORS or relative paths):

```bash
# using Python 3 (works in macOS zsh)
cd /path/to/cinf301-spr26-g3boys
python3 -m http.server 8000

# then open http://localhost:8000/first-page/index.html
```

Notes & suggestions
-------------------

- The second page reproduces the look of the first but intentionally replaces semantic tags and the HTML table with `div`-based structures using CSS Grid. This is for learning and demonstration purposes.
- If you'd like the second page to match the first page even more closely, I can tweak spacing, typography, and responsive breakpoints.

Authors
-------

Temirlan, Mohammed, Michael (team members)

