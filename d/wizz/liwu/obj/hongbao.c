#include <ansi.h>
int do_lingwu(string arg);

inherit ITEM;

void create()
{
        set_name(HIR "���" NOR, ({"hongbao", "hong bao"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "Ʈ�������Ĵ������ף����´�����,�Ͽ쿪��chai������ѣ���\n");
                set("value", 100000);
        }
        setup();
}

void init()
{
         if (!wizardp(this_player())) {
                set("no_get"," �ٺ٣����ΰ�! \n");
                set("no_drop","��ô����Ķ�������������! \n");
                set("no_give","��̫�����˰ɣ�\n");
                set("no_put","��������ˣ�\n");
                set("no_sell","��ô����Ķ�����������������ģ�\n");
        }
        add_action("do_kai", "chai");
}

int do_kai(string arg)
{
        int exper,dx,tt1,tt2,qn,improve=0;
        object me = this_player();

        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n"); 

        if ( this_object()->query("owner") != me->query("id")){
                message_vision(HIR"\n͵������������Ρ�\n"NOR,me);
                me->move("/d/wiz/jail");
                destruct(this_object());
                return 1;
        }
        dx= me->query("daoxing");
        qn= me->query("potential");
        if( (int)me->query("potential") > (int)me->query("learned_points"))             
                qn=(int)me->query("potential")-(int)me->query("learned_points");

        exper = me->query("combat_exp");
        improve=exper/50+random(exper/30)+3000;
        tt1= qn/50+random(qn/30)+3000;
        tt2= dx/50+random(dx/30)+3000;
        me->set("daoxing",dx + tt2);
        message_vision(HIY+me->name()+"�ĵ��д���"+tt2+"�㡣��\n"NOR,me);
        me->set("combat_exp",exper+improve);
        message_vision(HIY+me->name()+"����ѧ����"+improve+"�㡣��\n"NOR,me);
        me->add("potential",tt1);
        message_vision(HIY+me->name()+"��Ǳ�ܴ���"+tt1+"�㡣��\n"NOR,me);
        if( random(21) < 2){
                message_vision(HIY"��ϲ����,"+me->name()+"����ͷ������\n"NOR,me);
                switch(random(4)){
                        case 0:
                                me->add("str",1);              
                                message_vision(HIY+me->name()+"��������һ�㡣��\n"NOR,me);
                                me->add("cor",1);
                                message_vision(HIY+me->name()+"�ĵ�ʶ��������һ�㡣\n"NOR,me);
                        break;
                        case 1:
                                me->add("per",1);
                                message_vision(HIY+me->name()+"����ò��Ư����һ�㡣\n"NOR,me);
                                me->add("cor",1);
                                message_vision(HIY+me->name()+"�ĵ�ʶ��������һ�㡣\n"NOR,me);
                        break;
                        case 2:
                                me->add("cor",1);
                                message_vision(HIY+me->name()+"�ĵ�ʶ��������һ�㡣\n"NOR,me);
                                me->add("cps",1);
                                message_vision(HIY+me->name()+"�Ķ�����������һ�㡣\n"NOR,me);
                        break;
                        case 3:
                                me->add("cps",1);
                                message_vision(HIY+me->name()+"�Ķ�����������һ�㡣\n"NOR,me);
                                me->add("str",1);              
                                message_vision(HIY+me->name()+"��������һ�㡣��\n"NOR,me);
                        break;
                        case 4:
                                me->add("cps",1);
                                message_vision(HIY+me->name()+"�Ķ�����������һ�㡣\n"NOR,me);
                                me->add("per",1);
                                message_vision(HIY+me->name()+"����ò��Ư����һ�㡣\n"NOR,me);
                        break;
                 }      
        }
        else {
                message_vision(HIY"��ϲ����,"+me->name()+"û����ͷ��,��ϧѽ,���������ɡ���\n"NOR,me);
        }
        destruct(this_object());
        return 1;              
}


