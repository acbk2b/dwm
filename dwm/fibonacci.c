/*
 * Taken and modified from the following patch to work with fullgaps instead of vanitygaps:
 * https://dwm.suckless.org/patches/vanitygaps/dwm-vanitygaps-6.2.diff
 */

void
getgaps(Monitor *m, int *oh, int *ov, int *ih, int *iv, unsigned int *nc)
{
	unsigned int n, oe, ie;
  oe = ie = 1;
	Client *c;

	for (n = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next), n++);
	
  *oh = m->gappx*oe; // outer horizontal gap
	*ov = m->gappx*oe; // outer vertical gap
	*ih = m->gappx*ie; // inner horizontal gap
	*iv = m->gappx*ie; // inner vertical gap
	*nc = n;            // number of clients
}


void
fibonacci(Monitor *m, int s)
{
	unsigned int i, n;
	int nx, ny, nw, nh;
	int oh, ov, ih, iv;
	int nv, hrest = 0, wrest = 0, r = 1;
	Client *c;

	getgaps(m, &oh, &ov, &ih, &iv, &n);
	if (n == 0)
		return;

	nx = m->wx + ov;
	ny = m->wy + oh;
	nw = m->ww - 2*ov;
	nh = m->wh - 2*oh;

	for (i = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next)) {
		if (r) {
			if ((i % 2 && (nh - ih) / 2 <= (bh + 2*c->bw))
			   || (!(i % 2) && (nw - iv) / 2 <= (bh + 2*c->bw))) {
				r = 0;
			}
			if (r && i < n - 1) {
				if (i % 2) {
					nv = (nh - ih) / 2;
					hrest = nh - 2*nv - ih;
					nh = nv;
				} else {
					nv = (nw - iv) / 2;
					wrest = nw - 2*nv - iv;
					nw = nv;
				}

				if ((i % 4) == 2 && !s)
					nx += nw + iv;
				else if ((i % 4) == 3 && !s)
					ny += nh + ih;
			}

			if ((i % 4) == 0) {
				if (s) {
					ny += nh + ih;
					nh += hrest;
				}
				else {
					nh -= hrest;
					ny -= nh + ih;
				}
			}
			else if ((i % 4) == 1) {
				nx += nw + iv;
				nw += wrest;
			}
			else if ((i % 4) == 2) {
				ny += nh + ih;
				nh += hrest;
				if (i < n - 1)
					nw += wrest;
			}
			else if ((i % 4) == 3) {
				if (s) {
					nx += nw + iv;
					nw -= wrest;
				} else {
					nw -= wrest;
					nx -= nw + iv;
					nh += hrest;
				}
			}
			if (i == 0)	{
				if (n != 1) {
					nw = (m->ww - iv - 2*ov) - (m->ww - iv - 2*ov) * (1 - m->mfact);
					wrest = 0;
				}
				ny = m->wy + oh;
			}
			else if (i == 1)
				nw = m->ww - nw - iv - 2*ov;
			i++;
		}

		resize(c, nx, ny, nw - (2*c->bw), nh - (2*c->bw), False);
	}
}


void
dwindle(Monitor *mon) {
	fibonacci(mon, 1);
}

void
spiral(Monitor *mon) {
	fibonacci(mon, 0);
}
