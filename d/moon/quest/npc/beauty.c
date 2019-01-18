//Cracked by Roath


inherit NPC;

void create()
{

string* name=({"Сè��","С����","С����","С��","�ñ���","С����","С����","С�","С����",
               "С����",});
int r=random(sizeof(name));
  set_name(name[r],({"little elf","goodkid","baobao"}));
  set("age", random(9)+10);

  set("daoxing", 1200000);
  set("combat_exp", 10000);
  set("attitude", "friendly");
  set_weight(1000000000);
  set("per",30);
  if (random(2)) set("gender","Ů��");
  set("max_kee", 1000);
  set("kee",1000);
  set("sen",2000);
  set("max_sen", 2000);
  set("max_force", 500);
  set("force", 500);
  set("force_factor", 20);
  set("max_mana", 3000);
  set("mana", 3000);
  set("mana_factor", 100);


  set_skill("spells", 180);
  set_skill("dao", 180);
  
  set_skill("dodge", 50);
  set_skill("parry", 50);
  map_skill("spells", "dao");
  set("chat_chance_combat", 20);
  set("chat_msg_combat", ({
        (: cast_spell, "thunder" :),
        (: cast_spell,"light" :),
        (: cast_spell, "dingshen":),
  }));


    setup();
}
varargs int receive_damage(string type, int damage, object who) {
 return 1;
}
varargs int receive_wound(string type,int damage,object who) {
  return 1;
}
  

int accept_object(object me, object ob)
{
    string unit=ob->query("unit");
    if (!unit) unit="��";
    message_vision("$N��$nһ"+unit+ob->name()+"��\n",me,this_object());
    if (ob->move(this_object()))
      call_out("post_accept",1,me,ob);
    return 2;
}

void post_accept(object me,object ob) {

  object who=this_object();

  if (!ob) return;
  if (!me) return;
  if( !ob->query("food_remaining") ) {
     message_vision("$N��ë���׵�צ������$n���˿������Ӵ���ȥ�����ᡣ\n",who,ob);
     message_vision("$N������ش��˸���Ƿ�����ְ�$n�����˵��ϡ�\n\n",who,ob);
     ob->move(environment(me));
  } else {
     message_vision("$N���˵�������$n�Ļ�������ͷ������$n������\n\n",who,me);
     while (ob && ob->query("food_remaining") && command("eat "+ob->query("id")));
     if (250<=who->query("food")) {
        message_vision("$N��������������Ķ�Ƥ������ݴ���˯��ȥ�ˡ�\n\n",who);
        destruct(who);
     } else message_vision("$N����δ���������Ķ��ӣ�����$n����ֱ����ˮ��\n\n",who,me);
   }
   return;
}
