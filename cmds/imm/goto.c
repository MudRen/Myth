// goto.c
// modified by tool on 96/10/05

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int goto_inventory = 0;
        object obj, ridee;
        string msg, ridemsg;
     if (! SECURITY_D->valid_grant(me, "(immortal)")) return 0;
       if (me != this_player()) return 0;

        if( !arg ) return notify_fail("��Ҫȥ���\n");

        if( me->over_encumbranced() )
                   return notify_fail("�㸺��̫���ˣ�\n");

        if( sscanf(arg, "-i %s", arg) ) goto_inventory = 1;

        if( !arg ) return notify_fail("��Ҫȥ���\n");

        obj = find_player(arg);
        if(!obj) obj = find_living(arg);
       
	if(!obj) obj = LOGIN_D->find_body(arg);
	/* added by mon. 2/23/97 */
	if(!obj) obj = find_object(arg);

	if(!obj || !me->visible(obj)) {
                arg = resolve_path(me->query("cwd"), arg);
                if( !sscanf(arg, "%*s.c") ) arg += ".c";
                if( !(obj = find_object(arg)) ) {
                        if( file_size(arg)>=0 )
                                return me->move(arg);
                        return notify_fail("û�������ҡ������ط���\n");
                }
        }

        if(!goto_inventory && environment(obj))
                obj = environment(obj);

        if( !obj ) return notify_fail("������û�л������� goto��\n");

      if(!me->query("env/invisibility")) {
        if( stringp(msg = me->query("env/msg_mout")) ) {
           msg = replace_string(msg, "$BLK$", BLK);
           msg = replace_string(msg, "$RED$", RED);
           msg = replace_string(msg, "$GRN$", GRN);
           msg = replace_string(msg, "$YEL$", YEL);
           msg = replace_string(msg, "$BLU$", BLU);
           msg = replace_string(msg, "$MAG$", MAG);
           msg = replace_string(msg, "$CYN$", CYN);
           msg = replace_string(msg, "$WHT$", WHT);
           msg = replace_string(msg, "$HIR$", HIR);
           msg = replace_string(msg, "$HIG$", HIG);
           msg = replace_string(msg, "$HIY$", HIY);
           msg = replace_string(msg, "$HIB$", HIB);
           msg = replace_string(msg, "$HIM$", HIM);
           msg = replace_string(msg, "$HIC$", HIC);
           msg = replace_string(msg, "$HIW$", HIW);
           msg = replace_string(msg, "$NOR$", NOR);
           if (msg != "") message_vision(msg+NOR+"\n", me);
        }
        else
                message_vision(HIM"ֻ��һ���������$N����Ӱ�Ѿ������ˡ�\n"NOR, me);
      }

	if (ridee = me->ride())
        {
          ridemsg = ridee->query("ride/msg")+"��"+ridee->name();
	  ridee->move(obj);
	}  
	else
	  ridemsg = "";
        me->move(obj);

      if(!me->query("env/invisibility")) {
        if( stringp(msg = me->query("env/msg_min")) )
        {
           msg = replace_string(msg, "$BLK$", BLK);
           msg = replace_string(msg, "$RED$", RED);
           msg = replace_string(msg, "$GRN$", GRN);
           msg = replace_string(msg, "$YEL$", YEL);
           msg = replace_string(msg, "$BLU$", BLU);
           msg = replace_string(msg, "$MAG$", MAG);
           msg = replace_string(msg, "$CYN$", CYN);
           msg = replace_string(msg, "$WHT$", WHT);
           msg = replace_string(msg, "$HIR$", HIR);
           msg = replace_string(msg, "$HIG$", HIG);
           msg = replace_string(msg, "$HIY$", HIY);
           msg = replace_string(msg, "$HIB$", HIB);
           msg = replace_string(msg, "$HIM$", HIM);
           msg = replace_string(msg, "$HIC$", HIC);
           msg = replace_string(msg, "$HIW$", HIW);
           msg = replace_string(msg, "$NOR$", NOR);
           if (msg != "") message_vision(msg+NOR+"\n", me);
        }
        else
                message_vision(HIM"$N"+ridemsg+"ͻȻ������һ������֮�С�\n"NOR, me);
      }

        return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : goto [-i] <Ŀ��>

���ָ��Ὣ�㴫�͵�ָ����Ŀ��. Ŀ�������һ��living �򷿼�
�ĵ���. ���Ŀ����living , ��ᱻ�Ƶ����Ǹ���ͬ���Ļ���.
����м��� -i ������Ŀ���� living, ����ᱻ�Ƶ��� living ��
�� inventory ��.

HELP
    );
    return 1;
}

