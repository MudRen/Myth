#include <ansi.h>
int do_lingwu(string arg);

inherit ITEM;

 void create()
{
        set_name(HIR "���պ��" NOR, ({"hongbao", "hong bao"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�������������Ľ������ף��ҿ���,�Ͽ쿪��chai������ѣ���\n");
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

        object baoshi,me;
        me = this_player();


        if (!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");

        if(random(400)<2)
        {
         baoshi=new("/d/quest/baoshi/baoshi");
        
         "/d/quest/baoshi/baoshi"->changename(baoshi,1+random(7));
          baoshi->move(me);
         message_vision(HIY"���������$N������ϲ��ϲ�����õ���ο���ˡ�\n"NOR,me);
         message_vision(HIY"$N�õ�һ��"+baoshi->name()+"��\n"NOR,me);
         destruct(this_object());
         return 1;
         }
         else if( random(1000) < 2)
        {
        dx= me->query("daoxing");
        qn= me->query("potential");
        if( (int)me->query("potential") > (int)me->query("learned_points"))
                        qn=(int)me->query("potential")-(int)me->query("learned_points");

        exper = me->query("combat_exp");
        improve=exper/50+random(exper/30)+3000;
        tt1= qn/100+random(qn/100)+300;
        tt2= dx/100+random(dx/100)+300;
        if(tt2 > 20000) tt2=20000;
        if(improve > 20000) improve=20000;
        message_vision(HIY"���������$N������ϲ��ϲ�����õ����Ƚ��ˡ�\n"NOR,me);
        me->set("daoxing",dx + tt2);
        message_vision(HIY+me->name()+"�ĵ��д���"+tt2+"�㡣��\n"NOR,me);
        me->set("combat_exp",exper+improve);
        message_vision(HIY+me->name()+"����ѧ����"+improve+"�㡣��\n"NOR,me);
        me->add("potential",tt1);
        message_vision(HIY+me->name()+"��Ǳ�ܴ���"+tt1+"�㡣��\n"NOR,me);
        }else
        {
               tell_object(me,HIY"ͻȻ�������������$N̾������ϧѽ���Ͳ���һ�㣬������õ����Ƚ�����Ŭ���ɡ�\n"NOR);

         

          if( random(2500) < 2 && random(20)==1)
           {
                message_vision(HIY"��ϲ����,"+me->name()+"����ͷ������\n"NOR,me);
         
                me->add("balance",30000000);
                message_vision(HIY+me->name()+"�Ĵ��������3000���ƽ�\n"NOR,me);
             }
             else {
                tell_object(me,HIY"��ϲ����,"+me->name()+"û����ͷ��,��ϧѽ,�´������ɡ���\n");
                  if (random(1500) <2 && random(6)==1)
                  {
                  baoshi=new("/d/quest/baoshi/baoshi");
                  baoshi->move(me);
                  "/d/quest/baoshi/baoshi"->changename(baoshi,29+random(7));
                  message_vision(HIY"���������$N������ϲ��ϲ�����õ��ر��ˡ�\n"NOR,me);
                  message_vision(HIY"$N�õ�һ��"+baoshi->name()+"��\n"NOR,me);
                  }
                  }
         }
           
        destruct(this_object());
        return 1;


}




