#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
    set_name(HIM "����֮��" NOR, ({ "flower" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�使����������մ��������̻�ľ���֮����\n");
                set("unit", "��");
                set("value", 6); 
                set("no_get", 1);
                set("material", "plant");
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 3);
                set("wear_msg", "$N����ذ�һ��$n����ͷ�ϡ�\n");
                set("unwield_msg", "$N����ذ�$n��ͷ�ϳ���������\n");
                set("female_only", 1);

        }
        setup();
}

void init()
{
        add_action("do_get","zhai");
}

int do_get(string arg)
{
        object me,ob;
        me=this_player();
        ob=this_object(); 

        if( !arg ) return notify_fail("��Ҫ����ʲ�ᶫ����\n");
        if (arg=="flower" ) 
        {
                write(HIM"����֮��"NOR+HIG"�г�����һֻС���飬\n
С�������ų��˵��лл��⿪�˵�������ӡ������ذɣ�\n"NOR);
                ob->move(me);   
                message_vision(HIG"$N��һ������͵�����һ�����䡣\n"NOR, me); 
                me->move("/d/quest/tulong/spirit5");
                me->set_temp("m_success/����",1);
                destruct(ob);        
                return 1;
         }
}


