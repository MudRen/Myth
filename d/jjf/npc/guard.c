// xiaojie.c

inherit NPC;
void create()
{
       set_name("Уξ", ({"xiao wei", "wei", "xiao"}));
       set("long","�������ļҽ���������������Ȼ��\n");
       set("gender", "����");
       set("age", 28);
       set("attitude", "peaceful");
        set("per", 25);
        set("force", 300);
        set("max_force", 300);
        set("force_factor", 15);
	
        set("shen_type", 1);
        set("combat_exp", 15000+random(3000));
        set_skill("spear", 40);
        set_skill("parry", 40);
	set_skill("move", 40);
	set_skill("yanxing-steps", 15);
	set_skill("bawang-qiang", 15);
	map_skill("dodge", "yanxing-steps");
	map_skill("spear", "bawang-qiang");
	map_skill("parry", "bawang-qiang");
        set_skill("dodge", 40);

        setup();
        carry_object("/d/obj/weapon/spear/changqiang")->wield();
        carry_object("/d/obj/cloth/bingfu")->wear();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
  if( !ob || environment(ob) != environment() ) return;
  if (ob->query_temp("mark/��������"))
    {
      switch( random(1) ) {
      case 0:
	command("say ����˽�����أ�ɱ���⣡\n");
	command("kill "+(string)(ob->query("id")));
	break;
      }
    }
}

