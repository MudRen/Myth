// team command: emote
// by mudring@sjsh......

#include <ansi.h>

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object *t;
        string vb, emote_arg, msg;

        if (! arg) arg = "...";

        if (! pointerp(t = me->query_team()))
                return notify_fail("�����ڲ�û�кͱ�����ɶ��顣\n");
        if( sscanf(arg, "%s %s", arg, emote_arg)!= 2 )
        {
            vb = arg;
            emote_arg = "";
        }
        if (!(msg = EMOTE_D->do_emote(me, vb, emote_arg, 1, 0, 0)))
            return 0;
        message("team", HIW "�����顿" + msg + NOR, t);
        return 1;
}

