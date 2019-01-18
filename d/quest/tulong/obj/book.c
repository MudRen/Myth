#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW"��������"NOR, ({ "spirit book", "book"}));
        set_weight(0);
        if( clonep() )
            set_default_object(__FILE__);
        else {
            set("unit", "��");
            set("long","һ�������ġ������������ҳ��д�ţ�\n\n      "HIC"������ʵ�Ľ���\n\n"NOR);
            set("value", 2000000);
            set("material", "paper");
            set("skill", ([
                "name": "literate",    // name of the skill
                "exp_required": 1000,    // minimum combat experience required
                "sen_cost":    2,    // sen cost every time study this
                "difficulty":   10,    // the base int to learn this skill
                "max_skill":   160,    // the maximum level you can learn to
                "min_skill":   10,    // minimun level required
            ]) );
        }
}
int query_autoload()
{
        return 1;
}

void init()
{
    add_action("do_getblade","getblade");
}
int do_getblade(string arg)
{
        object me = this_player ();
        object ob;

        if(!me->query_temp("spiritagree") && (string)me->query("id")!="wuyou" ) 
                return notify_fail("��û�õ�����������������ô��Ϊ�㿪���أ�\n");  
        if (  present("spirit blade", me) ) 
                return notify_fail("�����ϲ�����һ����\n");  
        if( (int)me->query("sen") < 500 )
                return notify_fail("��ľ����޷����У���Ҫ��ǿ��\n");
        message_vision(HIY"$N"+HIY"̯��"NOR+HIW"���������"NOR+HIY"�����������дʡ�\n"NOR, me); 
        message_vision(HIY"��âէ��һ������������������ľ��鵶�����ڹ�â�С�\n"NOR, me);

         me->receive_damage("sen", 150);
        ob = new("/d/quest/tulong/obj/blade");
        ob->move(me);
        return 1;
}

