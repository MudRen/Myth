

#include <ansi.h>
inherit NPC;

int heal_other();

void create()
{
        set_name("�칬�˱�", ({ "shang bing", "bing" }));
        set("gender", "����" );//�Ա��������Ӧ
        set("long",
"�칬�����ߣ����ػ��칬�в��ұ��������ˡ�\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
        set("nickname",HIC"�����ػ��칬"NOR);
        set("kee",300);
        set("sen",300);
        set("max_kee",400+random(590));
        set("max_sen",400+random(590));
        set("per", 25);
        set("age", 22);
        set("combat_exp", 200000+random(300000));
        set("chat_chance", 5);
        set("chat_msg", ({
                "�칬�˱�˵������ѽѽ�����۰�����\n",
                "�칬�˱�˵�������ȫ����λ���ѣ����ܲ�ʧ�칬��\n",
                (: random_move :),
        }) );

        set_skill("unarmed", 100+random(150));
        set_skill("blade", 100+random(150));
        set_skill("parry", 100+random(150));
        set_skill("dodge", 100+random(150));
        set("inquiry", ([
                "����" : "лл��λ�ɼң���Ը���ұ(jiuzhi)�ң���\n",
        ]) );   
        
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 20);

if (random(20)>15)
{
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 200);
}

        setup();

}
void init( )
{
        object ob;
        add_action("heal_other","jiuzhi");
        call_out("hunting",180);
}

void hunting()
{
        object ob=this_object();
        write(HIR"�칬�˱�����������Ϊ��ұ�ƣ���Ѫ������\n"NOR);
        destruct(ob);
}



int heal_other()

{
        object me=this_player(); 
        object ob=this_object(); 

        if (me->query("gender")=="����")
                return notify_fail(HIC"�����²��ʺϴ������������㻹��ȥ���������ɡ�\n"NOR);

        if ( (int)me->query("sen")<20)
                return notify_fail("��̫���ˣ�ЪϢһ�°ɡ�\n");

        if (me->query_temp("guo/sanbing")>9)
                return notify_fail("�����Ѿ�ұ�ƺ��ˣ�\n");

       message_vision(HIB"$N�������������ڹ�������������$n���ģ������ؽ���������$n����....��\n"NOR,me,ob);
       me->add("sen",-me->query("eff_jing")/10);
       me->add_temp("guo/sanbing",1);
       if ( (int)me->query_temp("guo/sanbing")==8)

      {
            message_vision(CYN"$N���˲��ã�$N��ͷ��ð������ĺ��飬$n�³�һ����Ѫ����ɫ������������ˡ�\n"NOR,me,ob);
            me->delete_temp("guo/sanbing");
            if((int)me->query("combat_exp") < 1000000)   
            {
                message("vision", me->name() + HIG"���ڳɹ��ľ�ұ���칬�˱�,������200����,һ������к�100Ǳ�ܡ�\n"NOR, me);
                me->add("combat_exp",200);
                me->add("daoxing",400);
                me->add("potential",100);
                me->add("weiwang",1);
                destruct(ob);
              }
        message("vision", me->name() + HIG"�ɹ��ľ�ұ���칬�˱���\n"NOR, me);
        me->add("score",1);
        destruct(ob);

      
      }

      return 1;

} 


