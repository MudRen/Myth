// cc.c

#include <ansi.h>

int main(object me, string arg)
{
       if (me != this_player()) return 0;
     if (! SECURITY_D->valid_grant(me, "(immortal)"))
             return 0;
        if (!arg) return 0;
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$U$", U);
        arg = replace_string(arg, "$NOR$", NOR);
    arg = replace_string(arg, "$BLINK$", BLINK);
    arg += NOR;
        seteuid(getuid());
if (is_root(me))
    return me->force_me(color_filter(arg));
else return me->force_me(arg);
}

int help(object me)
{
        write(@HELP
ָ���ʽ : cc ����
 
���ָ�������������������ɫ��

HELP
"                        $NOR$ - �ָ�������ɫ\n"
"$RED$ - "RED"��ɫ"NOR"         $HIR$ - "HIR"����ɫ\n"NOR
"$GRN$ - "GRN"��ɫ"NOR"         $HIG$ - "HIG"����ɫ\n"NOR
"$YEL$ - "YEL"����ɫ"NOR"               $HIY$ - "HIY"��ɫ\n"NOR
"$BLU$ - "BLU"����ɫ"NOR"               $HIB$ - "HIB"��ɫ\n"NOR
"$MAG$ - "MAG"ǳ��ɫ"NOR"               $HIM$ - "HIM"�ۺ�ɫ\n"NOR
"$CYN$ - "CYN"����ɫ"NOR"               $HIC$ - "HIC"����ɫ\n"NOR
"$WHT$ - ǳ��ɫ         $HIW$ - "HIW"��ɫ\n"NOR
@HELP 

����ϵͳ�Զ������ִ�β�˼�һ�� $NOR$��
HELP
);
        return 1;
}

