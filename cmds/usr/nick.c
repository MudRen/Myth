// nick.c
#include <ansi.h>

inherit F_CLEAN_UP;
string replace_color(string,int);
int help(object);
int wiz_set(string,string,string,int);

int main(object me, string arg)
{
        string dest;
        if (me->is_busy()) return notify_fail("��������æ���أ�\n");
        if( !arg ) return help(me);     
        if(sscanf(arg,"-title %s,%s",dest,arg)==2)
        {
                if(!wizardp(me))
                        return notify_fail("�������ֻ������ʦʹ�á�\n");
                if(wiz_level(me)<wiz_level("(immortal)")&&(dest!="me"&&dest!=me->query("id")))
                        return notify_fail("���Ȩ�޲����������������\n");
                return wiz_set(dest,arg,"title",1)?1:notify_fail("����ʧ�ܡ�\n");
        }
        if(sscanf(arg,"-name %s,%s",dest,arg)==2)
        {
                if(!wizardp(me))
                        return notify_fail("�������ֻ������ʦʹ�á�\n");

                if(wiz_level(me)<wiz_level("(arch)")&&(dest!="me"&&dest!=me->query("id")))
                        return notify_fail("���Ȩ�޲����������������\n");
                return wiz_set(dest,arg,"name",0)?1:notify_fail("����ʧ�ܡ�\n");
        }
        if(sscanf(arg,"-nick %*s")==1)
                sscanf(arg,"-nick %s",arg);
        if(sscanf(arg,"%s,%s",dest,arg)==2)
        {
                if(wiz_level(me)<wiz_level("(apprentice)"))
                        return notify_fail("�������ֻ����С�����ϼ������ʦִ�С�\n");
                return wiz_set(dest,arg,"nickname",1)?1:notify_fail("����ʧ�ܡ�\n");
        }
        if( strlen(replace_color(arg,0)) > 20 )
                return notify_fail("�º�̫���ˣ�������һ����һ��ġ�����һ��ġ�\n");
        if (!wizardp(me)) me->start_busy(5);
        return wiz_set("me",arg,"nickname",1)?1:notify_fail("����ʧ�ܡ�\n");
        write("Ok.\n");
        return 1;
}
int wiz_set(string str1,string str2,string prop,int color_flag)
{
        object ob,me;
        me=this_player(1);
        if(str1=="me")
                ob=this_player(1);
        else
                if(!objectp(ob=present(str1,environment(me))))
                        if(!objectp(ob=find_player(str1)))
                                if(!objectp(ob=find_living(str1)))
                                {
                                        tell_object(me,"���ܷ��ֲ�������("+str1+")��\n");
                                        return 0;
                                }
        if(wiz_level(me)<wiz_level(ob))
        {
                tell_object(me,"���Ȩ�޲�����\n");
                return 0;
        }
        if((prop=="title"&&wizardp(me))||prop=="nickname")
                if(str2=="cancel")
                {
                        ob->delete(prop);
                        message_vision("$N��"+prop+"������ˡ�\n",ob);
                        return 1;
                }
        str2=replace_color(str2,color_flag);
        message_vision("$N��"+prop+"���趨Ϊ:"+str2+"\n",ob);
        ob->set(prop,str2);
        return 1;
}

string replace_color(string arg,int flag)
{
        arg = replace_string(arg, "$BLK$", flag?BLK:"");
        arg = replace_string(arg, "$RED$", flag?RED:"");
        arg = replace_string(arg, "$GRN$", flag?GRN:"");
        arg = replace_string(arg, "$YEL$", flag?YEL:"");
        arg = replace_string(arg, "$BLU$", flag?BLU:"");
        arg = replace_string(arg, "$MAG$", flag?MAG:"");
        arg = replace_string(arg, "$CYN$", flag?CYN:"");
        arg = replace_string(arg, "$WHT$", flag?WHT:"");
        arg = replace_string(arg, "$HIR$", flag?HIR:"");
        arg = replace_string(arg, "$HIG$", flag?HIG:"");
        arg = replace_string(arg, "$HIY$", flag?HIY:"");
        arg = replace_string(arg, "$HIB$", flag?HIB:"");
        arg = replace_string(arg, "$HIM$", flag?HIM:"");
        arg = replace_string(arg, "$HIC$", flag?HIC:"");
        arg = replace_string(arg, "$HIW$", flag?HIW:"");
        arg = replace_string(arg, "$BLINK$", flag?BLINK:"");
        arg = replace_string(arg, "$NOR$", flag?NOR:"");
        if(flag) arg+=NOR;
        return arg;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : 
nick <�º�> (��������ͨ���)
nick -title <id>,<�ִ�> ��idΪ<id>����ҡ�NPC��OBJECT�趨title���� (������wiz)
nick -name  <id>,<�ִ�> ��idΪ<id>����ҡ�NPC��OBJECT�趨name���� (������wiz)
nick <id>,<�º�>,       ��idΪ<id>����ҡ�NPC��OBJECT�趨id���� (������wiz)
����arch���¼�����ʦֻ�������Լ���tilte��name��
�κ�һ��������ܶԸ��߼������ʦ�����޸ġ�
�����ϣ��ʹ�� ANSI �Ŀ�����Ԫ�ı���ɫ�����������µĿ����ִ���
HELP +
"$BLK$ - "BLK"��ɫ"NOR"         $NOR$ - �ָ�������ɫ\n"+
"$RED$ - "RED"��ɫ"NOR"         $HIR$ - "HIR"����ɫ"NOR"\n"+
"$GRN$ - "GRN"��ɫ"NOR"         $HIG$ - "HIG"����ɫ"NOR"\n"+
"$YEL$ - "YEL"����ɫ"NOR"               $HIY$ - "HIY"��ɫ"NOR"\n"+
"$BLU$ - "BLU"����ɫ"NOR"               $HIB$ - "HIB"��ɫ"NOR"\n"+
"$MAG$ - "MAG"ǳ��ɫ"NOR"               $HIM$ - "HIM"�ۺ�ɫ"NOR"\n"+
"$CYN$ - "CYN"����ɫ"NOR"               $HIC$ - "HIC"����ɫ"NOR"\n"+
"$WHT$ - "WHT"ǳ��ɫ"NOR"               $HIW$ - "HIW"��ɫ"NOR"\n"+
"$BLINK$ - "BLINK"�ַ���˸"NOR
@HELP

����ϵͳ�Զ������ִ�β�˼�һ�� $NOR$��
�ִ���º�Ϊcancelʱ��ȡ���������ԣ����ֻ��ȡ��<�º�>��

HELP
        );
        return 1;
}

