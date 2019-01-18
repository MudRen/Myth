// huananhu.c
// Date: Sep.22 1997

inherit NPC;

void create()
{
        set_name("���ϻ�", ({ "huanan hu", "tiger","hu" }) );
        set("race", "Ұ��");
        set("age", 20);
        set("long", @LONG
һֻ�ý������ͻ�����ΰ���ˡ�


    ("`-''-/").___..--''"`-.
     `@_ @ )   `-.  (  *  ).`-.__.`)
     (_Y_.)'  ._   )  `._ `. ``-..-'
      _..`--'_..-_/  /--'_.' ,'
    (il),-''  (li),'  ((!.-'


LONG);
        set("attitude", "aggressive");
        set("shen_type", -1);

        set("limbs", ({ "��ͷ", "����", "ǰצ", "��ץ", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 3330000);
        set("kee", 2500);
        set("max_kee", 2500);
        set("sen", 2000);
        set("max_sen", 2000);
        set("force",3800);
        set("force_factor",3100);
        set("max_force",800);
        set("mana",500);
        set("max_mana",500);

        set_temp("apply/attack", 200);
        set_temp("apply/defense", 300);
        set_temp("apply/armor", 100);

        setup();

        set("chat_chance", 10);
        set("chat_msg", ({
                "�ϻ��ڿ�Ѳ���ŵ�����������ҳ���\n",
                "�ϻ����쳤Х������ɽ�ȣ���Ҷ��׹��\n",
        }) );
}

void init()
{       
        object ob; 

        ob = this_player();
        ::init();
        if( interactive(ob) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        if (ob->query_dex()<20 && !this_object()->query_temp("owner"))
        {
                message_vision( "ֻ������һ���硣
ֻ�������������˵�һ���죬����һֻ�����׶�������
�Ǵ���ֶ����ֿʣ�����ֻצ�ڵ����԰�һ������������һ�ˣ��Ӱ����ߥ��������\n",ob);
                message_vision("$N��һ��û�ж㿪��Ϊ���������˹�ȥ��\n\n",ob);
                ob->receive_wound("kee",200);
                ob->start_busy(2);
                this_object()->kill_ob(ob);
        }
}


