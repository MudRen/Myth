// more.c

#include <ansi.h>
#include <dbase.h>

#define LINES_PER_PAGE          24

void more(string cmd, string *text, int line)
{
        int i, j;
        string show;

        show = ESC + "[256D" + ESC + "[K";
        show = ESC + "[1A" + ESC "[256D" + ESC + "[K";

        switch (cmd)
        {
        default:
                i = line + LINES_PER_PAGE;
                if (i >= sizeof(text)) i = sizeof(text) - 1;
                show += implode(text[line..i], "\n") + "\n";
                if (i == sizeof(text) - 1)
                {
                        write(show);
                        return;
                }
                line = i + 1;
                break;

        case "b":
                line -= LINES_PER_PAGE * 2;
                if (line <= 0)
                {
                        line = 0;
                        show += WHT "-------- �ļ��Ķ��� --------\n" NOR;
                }

                i = line + LINES_PER_PAGE;
                if (i >= sizeof(text)) i = sizeof(text) - 1;
                show += implode(text[line..i], "\n") + "\n";
                line = i + 1;
                break;

        case "q":
                write(show);
                return;
        }
        show += sprintf(NOR WHT "== δ����� " HIY "%d%%" NOR
                        WHT " == (ENTER ������һҳ��q �뿪��b ǰһҳ)" NOR,
                        line * 100 / sizeof(text));
        write(show);
        input_to("more", text, line);
}

#define MAX_STRING_SIZE                 7000

void s_write(string msg)
{
        int n, nd;
        int len;

        len = strlen(msg);
        if (len > MAX_STRING_SIZE)
        {
                // the string too long ?
                n = 0;
                while (n < len)
                {
                        // show section of the string
                        nd = n + MAX_STRING_SIZE;
                        if (nd >= len) nd = len - 1;
                        write(msg[n..nd]);
                        n = nd + 1;
                }
        } else
                write(msg);
}

void start_more(string msg)
{
        int len;

        if (! stringp(msg) || (len = strlen(msg)) < 1)
                // û������
                return;

        if (query("env/no_more"))
        {
                s_write(msg);
                if (msg[len - 1] != '\n') write("\n");
                return;
        }

        write("\n");
        more("", explode(msg, "\n"), 0);
}

void more_file(string cmd, string file, int line, int total)
{
        int i;
        int key;
        string show;
        string content;
        string *text;
        int goto_line;
        int page;
        int not_show;

        show = ESC + "[256D" + ESC + "[K";
        show = ESC + "[1A" + ESC "[256D" + ESC + "[K";

        page = LINES_PER_PAGE;
        goto_line = line;

        if (! cmd) cmd = "";
        if (sscanf(cmd, "%d,%d", goto_line, page) == 2)
        {
                if (page < goto_line)
                {
                        i = goto_line;
                        goto_line = page;
                        page = i;
                }
                page = page - goto_line + 1;
        } else
        if (sscanf(cmd, "n%d", page))
                ;
        else
        if (sscanf(cmd, "%d", goto_line))
                ; else
        {
                switch (cmd)
                {
                default:
                        cmd = "";
                        break;

                case "b":
                        goto_line = line - LINES_PER_PAGE * 2;
                        if (goto_line > 1)
                                break;
                        // else continue to run selection "t"
                case "t":
                        goto_line = 1;
                        break;

                case "q":
                        write(show);
                        return;
                }
        }

        if (page > 301)
        {
                show += "������ʾ����������С�ڵ���300��\n";
                not_show = 1;
        } else
        {
                not_show = 0;

                if (! goto_line) goto_line = 1;
                if (! page) page = 1;

                if (goto_line < 0)
                {
                        // The goto line < 0, mean look bottom
                        goto_line += total;
                        if (goto_line  < 1)
                                goto_line = 1;
                }

                if (page < 0)
                {
                        // The page size < 0, mean look previous page
                        goto_line += page;
                        if (goto_line < 1)
                        {
                                page -= goto_line - 1;
                                goto_line = 1;
                        }
                        page = -page;
                }
        }

        line = goto_line;

        if (! not_show)
        {
                if (line == 1)
                        show += WHT "-------- �ļ��Ķ��� --------\n" NOR;
                else
                if (cmd != "")
                        show += sprintf(HIW "-------- �ӵ� %d �п�ʼ %d �� --------\n" NOR,
                                        goto_line, page);
        
                content = read_file(file, line, page);
                if (! content)
                {
                        i = 0;
                } else
                {
                        text = explode(replace_string(content, "\n", " \n") + " ", "\n");
                        if (page > sizeof(text))
                                page = sizeof(text);
                        for (i = 0; i < page; i++)
                                text[i] = sprintf(NOR "%-8d%s", i + line, text[i]);
                        content = implode(text[0..i - 1], "\n") + "\n";
                
                        show += content;
                }
        }

        if (not_show || i > 1)
        {
                show += NOR WHT "- δ��(" HIY + total +
                        NOR WHT ") - (�س�������"
                        HIY "q" NOR WHT " �뿪��"
                        HIY "b" NOR WHT " ǰһҳ��"
                        HIC "<num>" NOR WHT " ���� "
                        HIC "n" NOR WHT " �У�"
                        HIY "n" HIC "<num>" NOR WHT
                        "��ʾ���� " HIC "n" NOR WHT " ��)" NOR;
                s_write(show);
                input_to("more_file", file, line + page, total);
        } else
        {
                show += WHT "�Ķ���ϡ�\n" NOR;
                s_write(show);
        }
}

void start_more_file(string fn)
{
        if (file_size(fn) < 0)
        {
                write("û�� " + fn + " ����ļ��ɹ��Ķ���\n");
                return;
        }
        write("\n");
        more_file("t", fn, 1, file_lines(fn));
}
