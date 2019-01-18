// dahuandan.c �󻹵�

#include <ansi.h>
inherit ITEM;

void init()
{                                      
        add_action("do_eat", "eat");
        add_action("do_drop","drop");
}

void create()
{
        set_name(HIR "�󻹵�" NOR, ({"dahuan dan", "dan"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ���󻹵�����˵����������֮Ч��\n");
                set("value", 2000);
                set("no_sell",1);
                set("drug_type", "��Ʒ");
        }
        set("is_monitored", 1);
        setup();
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");

        me->add("combat_exp", (int)me->query("combat_exp") / 40);
        if( (int)me->query("potential") > (int)me->query("learned_points"))
                me->add("potential",(int)me->query("potential") - (int)me->query("learned_points") );
        me->skill_death_recover();
        me->add("daoxing",me->query("death/dx_loss"));
        me->save();

        if( userp(me) ) log_file("RECOVER", sprintf("%s(%s) Got recovered on %s.\n", me->name(1), geteuid(me), ctime(time()) ) );

        message_vision(HIR "\n$N����һ���󻹵���Ӳ�ǴӰ��޳��������ѣ������һ��С����\n\n" NOR, me);
        destruct(this_object());
        return 1;
}

int do_drop(string arg)
{
        object ob = this_object();
        object me = this_player();
        
        if(arg == "dahuan dan" || arg == "dan"){
                message_vision("�ÿ�ϧѽ����ô����ҩ��������"+me->query("name")+"�����ӵ��ˣ�"+ob->query("name")+"ת�ۼ����ʧ����Ӱ���١�\n",me,ob); 
                destruct(ob);
        }
        return 1;
}
