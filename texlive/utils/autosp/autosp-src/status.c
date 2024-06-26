/*  Copyright (C) 2014-21 R. D. Tennent School of Computing,
 *  Queen's University, rdt@cs.queensu.ca
 *
 *  This program is free software; you can redistribute it
 *  and/or modify it under the terms of the GNU General
 *  Public License as published by the Free Software
 *  Foundation; either version 2 of the License, or (at your
 *  option) any later version.
 *
 *  This program is distributed in the hope that it will
 *  be useful, but WITHOUT ANY WARRANTY; without even the
 *  implied warranty of MERCHANTABILITY or FITNESS FOR A
 *  PARTICULAR PURPOSE. See the GNU General Public License
 *  for more details.
 *
 *  You should have received a copy of the GNU General
 *  Public License along with this program; if not, write to
 *  the Free Software Foundation, Inc., 51 Franklin Street,
 *  Fifth Floor, Boston, MA 02110-1301, USA.
 */

# include "process_command.h"

char *ps(int spacing)
/* convert spacing value to note value(s)  */
{ s_n = s; 
  *s = '\0';
  if (spacing == MAX_SPACING) 
    sprintf(s, "MAX_SPACING");
  else if (spacing == 0)
    sprintf(s, "0");
  else 
  { int n = 1;
    while (true)
    { if (spacing >= SMALL_NOTE/n)
      { s_n = s_n + sprintf (s_n, "SP(%d)", n);
        spacing = spacing - SMALL_NOTE/n;
        if (spacing > 0) 
          s_n = s_n + sprintf (s_n, "+");
        else break;
      }
      n = 2*n;
    }
  }
  return s;
}

void 
note_segment (char *s)
{ char *t;
  t = strpbrk (s, "|&$");
  if (t == NULL) t = s + strlen (s);
  while (s < t)
  { fputc (*s, logfile); s++; }
  fputc ('\n', logfile);
}

void
status (int i)
{ 
  if (active[i])
  { fprintf (logfile, "notes[%d]=", i); note_segment (notes[i]); 
    fprintf (logfile, "current[%d]=", i); note_segment (current[i]); 
    fprintf (logfile, "spacings[%d]=%s\n", i, ps(spacings[i]));
    fprintf (logfile, "vspacing[%d]=%s\n", i, ps(vspacing[i]));
    fprintf (logfile, "outstrings[%d]=%s\n", i, outstrings[i]);
    if (xtuplet[i] > 1)
      fprintf (logfile, "xtuplet[%d]=%d\n", i, xtuplet[i]);
      
  }
}

void
status_spacing (void)
{
  fprintf (logfile, "spacing=%s\n", ps(spacing));
  fprintf (logfile, "old_spacing=%s\n", ps(old_spacing));
  fprintf (logfile, "spacing_staff=%d\n", spacing_staff);
  fprintf (logfile, "oldspacing_staff=%d\n", oldspacing_staff);
}

void
status_all (void)
{ int i;
  for (i=1; i <= nstaffs; i++)
    if (active[i]) status (i);
  status_spacing ();
  fprintf (logfile, "nastaffs=%d\n", nastaffs);
  if (dottedbeamnotes) 
    fprintf (logfile, "dottedbeamnotes == true\n");
}

void
status_collective (int i)
{ 
  if (active[i])
  { fprintf (logfile, "cspacing[%d]=%s\n", i, ps(cspacing[i]));
    fprintf (logfile, "collective[%d]=%s\n", i, collective[i]);
    fprintf (logfile, "first_collective[%d]=%d\n", i, first_collective[i]);
  }
}

void
status_beam (int i)
{ 
  if (active[i])
  { fprintf (logfile, "beaming[%d]=%s\n", i, ps(beaming[i])); }
}
