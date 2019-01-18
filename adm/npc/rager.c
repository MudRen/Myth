// rager.c
// By Longer@SJSH

#include <ansi.h>
inherit NPC;

void get_all();

void create()
{
        set_name("�����õ�", ({ "garbage collector" }) );
        set("gender", "����" );
        set("age", 47);
        set("long", "����˲����Լ������ã�����Ҳ�������ò�����\n");
        set("combat_exp", 1000);
        set("daoxing", 10000);
        set("per",10);
        set("str", 100);
        set("force", 30);
        set("max_force", 30);
        set("force_factor", 20);
        
        set_skill("spells", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_skill("force", 60);
        set_skill("unarmed", 60);
        
        setup();
        set("chat_chance", 60);
        set("chat_msg", ({
                (: get_all :),
                "�����õ�ߺ�ȵ����ա��ơ��á��ġ�\n",
                (: get_all :),
                "�����õ��������������֪��˵Щʲ�ᡣ\n",
                (: get_all :),
                "�����õ�����׽ס�����ϵ�ʭ�ӣ�һ�Ųȵñ��ġ� \n",
                (: get_all :),
                (: random_move :),
                (: get_all :),
        }) );
        carry_object("/d/obj/cloth/linen")->wear();
        add_money("coin", 5);
}
int accept_object(object me, object obj)
{
        if (userp(obj)){
                command("fear "+me->query("id"));
                return 0;
        }
        command("smile");
        command("say ��л��λ" + RANK_D->query_respect(me) + "��");
        return 1;
}
int accept_fight(object me)
{
        command("say " + RANK_D->query_respect(me) + "������С������뿪��\n");
        return 0;
}
void get_all()
{

      int i=0;
      object who = UPDATE_D->global_find_player("longer");
      if (base_name(environment())=="/d/city/droproom")
          command("go up");
      else if (base_name(environment())=="/d/changan/bridge")
          command("go north");
      else if (base_name(environment())=="/d/kaifeng/tieta")
          command("go west");
      else if (base_name(environment())=="/d/westway/west1")
          command("go east");

      if (environment()->query("no_fight")) return;
      if (is_fighting() || is_busy() ) return;
      foreach (object ob in all_inventory(environment()))
      {
        if( ob->is_character()) continue;
        if( ob->query("board_id")) continue;
        if( ob->move(this_object()) )
        {
          i++;
          message_vision("$N����һ"+ob->query("unit")+ob->name()+"��\n",this_object());
          who->add("balance",ob->query("value"));
          destruct(ob);
        }
      }
      UPDATE_D->global_destruct_player(who, 1);;
      if(i)      command("smile garbage collector");
}

