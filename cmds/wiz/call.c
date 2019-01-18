// call.c

inherit F_CLEAN_UP;
#include <ansi.h>

mixed query(string arg)
{
    if (arg && arg=="channel_id")
      return HIR"���г���(CALL)";
    return 0;
}

int main(object me, string arg)
{
    string objname, func, param, euid;
    object obj;
    mixed *args, result;
    int i;

    if (! SECURITY_D->valid_grant(me, "(wizard)")) 
        return 0; 

    if( arg )
    {
        if (sscanf(arg, "-%s %s", euid, arg)==2 )
        {
            if ((string)SECURITY_D->get_status(me) != "(admin)" )
                return notify_fail("�㲻���趨�Լ��� euid��\n");
            seteuid(euid);
        }
        else
            seteuid( geteuid(this_player(1)) );

    	if( sscanf(arg, "%s->%s(%s)", objname, func, param)!=3 )
        	return notify_fail("ָ���ʽ��call <���>-><����>( <����>, ... )\n");

    } else
        return notify_fail("ָ���ʽ��call <���>-><����>( <����>, ... )\n");

    obj = present(objname, environment(me));
    if(!obj) obj = present(objname, me);
    if(!obj) obj = find_player(objname);
    if(!obj || !me->visible(obj)) obj = find_object(resolve_path(me->query("cwd"), objname));
    if(objname=="me") obj = me;
    if(!obj) return notify_fail("�Ҳ���ָ���������\n");

    if(wizardp(obj) && wiz_level(me) < wiz_level(obj))
       return notify_fail("�㲻���趨�ȼ�����ߵ���ʦ״̬��\n");

    if ( userp(obj) && obj != me && wiz_level(me) < wiz_level("(arch)") ) 
        return notify_fail("ָ���ʽ��call <���>-><����>( <����>, ... )\n");

    if( userp(obj) )
    {
            if( obj != me )
            	log_file("static/CALL_PLAYER",
                    sprintf("%s(%s) call %s(%s)->%s(%s) on %s\n",
                            me->name(1), geteuid(me), obj->name(1), geteuid(obj), func, param,
                            ctime(time()) ) );
    } else if( !master()->valid_write( base_name(obj), me, "set" ) )
            return notify_fail("��û��ֱ�Ӻ����������ĺ�����Ȩ����\n");
            
	if(!wizardp(obj) && userp(obj))
	{
		log_file("static/CALL_USER",
                        sprintf("%s(%s) call %s(%s)->%s(%s) on %s\n",
                                me->name(1), geteuid(me), obj->name(1), geteuid(obj), func, param,
                                ctime(time()) ) );
    	CHANNEL_D->do_channel(this_object(),"chat",
                        sprintf("%s(%s) call %s(%s)->%s(%s) \n",
                                me->name(1), geteuid(me), obj->name(1), geteuid(obj), func, param,
                               ) );
     }
     
    CHANNEL_D->do_channel(this_object(),"sys",
                        sprintf("%s(%s) call %s(%s)->%s(%s) \n",
                                me->name(1), geteuid(me), obj->name(1), geteuid(obj), func, param,
                                 ) );

        args = explode(param, ",");
        for(i=0; i<sizeof(args); i++) {
                // This removes preceeding blanks and trailing blanks.
                parse_command(args[i], environment(me), "%s", args[i]);
                if( sscanf(args[i], "%d", args[i]) ) continue;
                if( sscanf(args[i], "\"%s\"", args[i]) ) continue;
                //args[i] = restore_variable(args[i]);
        }

        args = ({ func }) + args;

        result = call_other(obj, args);
        for(i=1; i<sizeof(args); i++)
                args[i] = sprintf("%O",args[i]);

    tell_object(me, sprintf("%O->%s(%s) = %O\n", obj, func, 
                implode(args[1..sizeof(args)-1], ", "), result));
        return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : call <���>-><����>(<����>, ...... )

����<���>���<����>���������<����>.

HELP
    );
    return 1;
}
