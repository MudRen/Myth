//copy from bone by repoo

#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;

void create()
{
        set_name(HIR"������"NOR, ({"sheli zi"}));
        set_weight(800);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "��������������γɵ������ӡ�\n");
                set("unit", "��");
                set("no_put", 1);
                set("is_monitored", 1);
                set("material", "bone");
        }
        setup();
}
int init()
{
        add_action("do_mo","mo");
        check_owner();
        return 1;
}
int do_mo(string arg)
{
        string type;
        object who = this_player();
        object ob;

        if(who->is_fighting())
                return notify_fail("��������˵��\n");
        if(who->is_busy())
                return notify_fail("����æ����!\n");
        if (!arg)
                return notify_fail("�����������ӱ��ʲô������(sword blade stick hammer fork axe spear staff whip mace)\n");
        else 
        {
                sscanf(arg,"%s",type);
                switch(type)
                {
                        case "sword":
message_vision(WHT"\n$N���������һ��"NOR+HIR"������"NOR+WHT"��ֻ���׹�һ����"+HIR" ������ "NOR+WHT"����������ɢ�����γ�һ��"NOR+HIR" տ¬"NOR+HIW"�� \n"NOR,who);
message("channel:rumor",YEL+"\n��"+HIB" �˲����� "NOR+YEL"��ĳ�ˣ�"+who->query("name")+"�õ�"+HIR" տ¬"+HIW"�� "NOR+YEL"�ˣ�\n\n"+NOR,users() );

                        ob = new("/d/shendian/babu/obj/gujian");
                        ob->move(who);
                        destruct(this_object());
                                break;
                        case "blade":
message_vision(WHT"\n$N���������һ��"NOR+HIR"������"NOR+WHT"��ֻ���׹�һ����"+HIR" ������ "NOR+WHT"����������ɢ�����γ�һ��"NOR+HIR" ����"NOR+HIW"�� \n"NOR,who);
message("channel:rumor",YEL+"\n��"+HIB" �˲����� "NOR+YEL"��ĳ�ˣ�"+who->query("name")+"�õ�"+HIR" ����"+HIW"�� "NOR+YEL"�ˣ�\n\n"+NOR,users() );
                        ob = new("/d/shendian/babu/obj/gudao");
                        ob->move(who);
                        destruct(this_object());
                                 break;
                        case "stick":
message_vision(WHT"\n$N���������һ��"NOR+HIR"������"NOR+WHT"��ֻ���׹�һ����"+HIR" ������ "NOR+WHT"����������ɢ�����γ�һ��"NOR+HIR" ����"NOR+HIW"�� \n"NOR,who);
message("channel:rumor",YEL+"\n��"+HIB" �˲����� "NOR+YEL"��ĳ�ˣ�"+who->query("name")+"�õ�"+HIR" ����"+HIW"�� "NOR+YEL"�ˣ�\n\n"+NOR,users() );
                        ob = new("/d/shendian/babu/obj/gustick");
                        ob->move(who);
                        destruct(this_object());
                                break;
                        case "hammer":
message_vision(WHT"\n$N���������һ��"NOR+HIR"������"NOR+WHT"��ֻ���׹�һ����"+HIR" ������ "NOR+WHT"����������ɢ�����γ�һ��"NOR+HIR" ����"NOR+HIW"�� \n"NOR,who);
message("channel:rumor",YEL+"\n��"+HIB" �˲����� "NOR+YEL"��ĳ�ˣ�"+who->query("name")+"�õ�"+HIR" ����"+HIW"�� "NOR+YEL"�ˣ�\n\n"+NOR,users() );
                        ob = new("/d/shendian/babu/obj/guhammer");
                        ob->move(who);
                        destruct(this_object());
                                break;
                        case "fork":
message_vision(WHT"\n$N���������һ��"NOR+HIR"������"NOR+WHT"��ֻ���׹�һ����"+HIR" ������ "NOR+WHT"����������ɢ�����γ�һ��"NOR+HIR" �·�"NOR+HIW"�� \n"NOR,who);
message("channel:rumor",YEL+"\n��"+HIB" �˲����� "NOR+YEL"��ĳ�ˣ�"+who->query("name")+"�õ�"+HIR" �·�"+HIW"�� "NOR+YEL"�ˣ�\n\n"+NOR,users() );
                        ob = new("/d/shendian/babu/obj/gufork");
                        ob->move(who);
                        destruct(this_object());
                                break;
                        case "axe":
message_vision(WHT"\n$N���������һ��"NOR+HIR"������"NOR+WHT"��ֻ���׹�һ����"+HIR" ������ "NOR+WHT"����������ɢ�����γ�һ��"NOR+HIR" ��Ȫ"NOR+HIW"�� \n"NOR,who);
message("channel:rumor",YEL+"\n��"+HIB" �˲����� "NOR+YEL"��ĳ�ˣ�"+who->query("name")+"�õ�"+HIR" ��Ȫ"+HIW"�� "NOR+YEL"�ˣ�\n\n"+NOR,users() );
                        ob = new("/d/shendian/babu/obj/guaxe");
                        ob->move(who);
                        destruct(this_object());
                                break;
                        case "spear":
message_vision(WHT"\n$N���������һ��"NOR+HIR"������"NOR+WHT"��ֻ���׹�һ����"+HIR" ������ "NOR+WHT"����������ɢ�����γ�һ��"NOR+HIR" ��¯"NOR+HIW"ǹ \n"NOR,who);
message("channel:rumor",YEL+"\n��"+HIB" �˲����� "NOR+YEL"��ĳ�ˣ�"+who->query("name")+"�õ�"+HIR"��¯"+HIW"ǹ"NOR+YEL"�ˣ�\n\n"+NOR,users() );
                        ob = new("/d/shendian/babu/obj/guqiang");
                        ob->move(who);
                        destruct(this_object());
                                break;
                        case "staff":
message_vision(WHT"\n$N���������һ��"NOR+HIR"������"NOR+WHT"��ֻ���׹�һ����"+HIR" ������ "NOR+WHT"����������ɢ�����γ�һ��"NOR+HIR" ����"NOR+HIW"�� \n"NOR,who);
message("channel:rumor",YEL+"\n��"+HIB" �˲����� "NOR+YEL"��ĳ�ˣ�"+who->query("name")+"�õ�"+HIR"����"+HIW"��"NOR+YEL"�ˣ�\n\n"+NOR,users() );
                        ob = new("/d/shendian/babu/obj/gustaff");
                        ob->move(who);
                        destruct(this_object());
                                break;
                       case "whip":
message_vision(WHT"\n$N���������һ��"NOR+HIR"������"NOR+WHT"��ֻ���׹�һ����"+HIR" ������ "NOR+WHT"����������ɢ�����γ�һ��"NOR+HIR" ����"NOR+HIW"�� \n"NOR,who);
message("channel:rumor",YEL+"\n��"+HIB" �˲����� "NOR+YEL"��ĳ�ˣ�"+who->query("name")+"�õ�"+HIR" ����"+HIW"�� "NOR+YEL"�ˣ�\n\n"+NOR,users() );
                        ob = new("/d/shendian/babu/obj/guwhip");
                        ob->move(who);
                        destruct(this_object());
                                break;
                       case "mace":
message_vision(WHT"\n$N���������һ��"NOR+HIR"������"NOR+WHT"��ֻ���׹�һ����"+HIR" ������ "NOR+WHT"����������ɢ�����γ�һ��"NOR+HIR" ����"NOR+HIW"�� \n"NOR,who);
message("channel:rumor",YEL+"\n��"+HIB" �˲����� "NOR+YEL"��ĳ�ˣ�"+who->query("name")+"�õ�"+HIR" ����"+HIW"�� "NOR+YEL"�ˣ�\n\n"+NOR,users() );
                        ob = new("/d/shendian/babu/obj/gumace");
                        ob->move(who);
                        destruct(this_object());
                                break;                                
                }
        return 1;
        }
}

