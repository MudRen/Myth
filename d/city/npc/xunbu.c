// xunpu.c Ѳ��
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("Ѳ��", ({ "xun bu", "bu", "xun" }));
        set("gender", "����");
        set("age", random(10) + 40);
        set("str", 25);
        set("dex", 16);
        set("long",       "���Ǹ�����ִ�й����Ѳ���������ɱ���ˣ����ǡ��������ܰ�������\n");
        set("combat_exp", 100000+random(6000000));
        set("shen_type", 1);
        set("attitude", "peaceful");
        set_skill("unarmed", 60+random(100));
        set_skill("force", 110);
        set_skill("sword", 360+random(200));
        set_skill("dodge", 660+random(200));
        set_skill("parry", 360+random(200));
        set_temp("apply/attack", 250+random(50));
        set_temp("apply/defense", 250+random(50));
        set_temp("apply/armor", 250+random(50));
        set_temp("apply/damage", 230+random(30));
        set("force", 3400+random(1500)); 
        set("maximum_force", 3400+random(1500));
		set("max_force", 3400+random(1500));
        set("enforce", 10+random(100));
        set("chat_chance", 20);
        set("chat_msg", ({
       "\nѲ���������ؿڣ�˵���������ڣ�˭��������ɱ�ˣ�˭ɱ���˾�Ҫ������\n",
       "\nѲ�������㼸�ۣ�˵�����ɱ�ɱ�˰�����������һ������Ź��㣡\n",
        "\nѲ��˵������ô����û��ɱ�ˣ����������ˣ�\n",
        (: random_move :)
        }) );
 
        setup();
        carry_object("/d/obj/weapon/sword/tiejian")->wield();
        carry_object("/d/obj/cloth/zhanpao")->wear();
}

void init()
{
        object ob;
        ::init();
        if (!living(this_object())) return;
        if (!userp(this_object())) return;

        if (interactive(ob = this_player())){
                        if ( (int)ob->query_condition("killer")) {
                    command("say "+ob->name()+"����ɱ���ˣ����������ӣ���");
			this_object()->set_leader(ob);

                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob);
                                        return ;
                }

                if (  ((int)ob->query_condition("killer")>0) && ob->query("race")=="����" 
                   && ((int)ob->query("summon_time")+3600)< time() ) {
                remove_call_out("summon_ob");
                call_out("summon_ob", 1, ob);
                                return;
        }

            add_action("do_kill","kill");
        }

}

void summon_ob(object ob)
{
    object room;

    if (!ob || environment(ob)!=environment())
            return;
       if( ob->query("env/invisibility") ) return;
       if( !userp(ob) && wizardp(ob) ) return;

        if (! room=find_object("/d/city/misc/dalao"))
            room=load_object("/d/city/misc/dalao");

	if (!this_player()->query_temp("armor/cloth") && this_player()->query("race")=="����" ) {
//        message_vision("\n$Nһ��ץס$n�����컯�գ��������ܣ����˷绯��\n\n",this_object(),ob);
        message_vision("\n$Nһ��ץס$n�����ӷ������컯�գ���ҡ���У����һ����ţ�\n\n",this_object(),ob);
        message_vision("$N����$n��������ȥ��\n",this_object(),ob);
        ob->move(room);
	ob->set("summon_time",time()+3600);
	message("vision",YEL+"\n\n���һ����һ���������ļһﱻ���˽�����\n\n"+NOR,room,({ob}));
	}
        if (! room=find_object("/d/city/baihu-w1"))
            room=load_object("/d/city/baihu-w1");
        this_object()->move(room);
}

int do_kill(string arg)
{
        object ob;
      if (!environment()) return 0;
        if (ob=present(arg,environment()))
        if (userp(ob)){

            command("say ���ڴ�ү��ǰ��Ұ������ѽ��");
            kill_ob(this_player());
        }
    return 0;
}

