//modified by vikee for xlqy
//modified by bbrbbt for xlqy
//2000-11-24 8:34

#include <ansi.h>
#include <combat.h>

inherit NPC;
#include <flowers.h>

string name;
int score;
int query_score() {return score;}
void cast_shiyue();

void set_skills(object);
void hurt(object,object);
void reward(object me, object victim, object weapon,int damage);

void create()
{
  name=flowers[random(sizeof(flowers))];
  set_name(name+"����", ({ "hua xianzi","xianzi","xian" }) );
  set("long",@LONG
һλƷò���������ʸ��ŵĻ����ӣ�����ɢ����һ�����㣬
�ȷǱ��꣬�ַ��̴���ƻ�����ǻ��㣬ʱ�̱任�����а�
��������
LONG);
  set("gender", "Ů��");
  set("age", 20);
  set("str", 10+random(21));
  set("dex", 10+random(21));
  set("int", 10+random(21));
  set("cor", 10+random(21));
  set("spi", 10+random(21));
  set("con", 10+random(21));  
  set("per", 10+random(21));

  set("combat_exp", 10000);
  set("daoxing", 10000);

  set_skill("unarmed", 80);
  set_skill("baihua-zhang",180);
  set_skill("parry", 80);
  set_skill("dodge", 80);
  set_skill("moondance",80);
  set_skill("force", 180);
  set_skill("spells", 180);
  set_skill("moonshentong",180);
  map_skill("spells","moonshentong");
  map_skill("dodge","moondance");
  map_skill("unarmed","baihua-zhang");
  set("max_kee", 1000);
  set("max_sen", 1000);
  set("mana", 4000);
  set("max_mana", 4000);
  set("mana_factor", 100);
  set("force", 2000);
  set("max_force", 1000);
  set("inquiry",([
    "��" : "�����Ҵ����(fight)�����Һ�����ˣ���Ȼ����ĺô���\n",
    "�ɻ�" : "�����Ҵ����(fight)�����Һ�����ˣ���Ȼ����ĺô���\n",
    "flower" : "�����Ҵ����(fight)�����Һ�����ˣ���Ȼ����ĺô���\n",
    "hua" : "�����Ҵ����(fight)�����Һ�����ˣ���Ȼ����ĺô���\n",
  ]));
  setup();
  if (clonep())  carry_object("/obj/loginload/skirt")->wear();
  if (clonep())  carry_object("/obj/loginload/shoes")->wear();
        set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
        (: cast_shiyue :),
        }) );

}

void cast_shiyue() {
     object target=query("target");
   if (!target) return;
  if (random(2)) return;
  if (target->query_condition("moon_poison")) return;
  if (query_condition("moon_poison")) return;

  command("cast shiyue");
  if (target->query_condition("moon_posion")) score*=2;
}

void unconcious() { die(); }

void die()
{
  command("drop all");
  message_vision(MAG"$N"+MAG"����һ�����㣬��ʧ�ں쳾֮�С�\n"NOR,this_object());
  destruct(this_object());
}

int accept_object(object me, object ob)
{
  object weapon=query_temp("weapon");
  string msg="$N";
  if (!mapp(ob->query("weapon_prop"))) return 0;
  message_vision("$N��$nһ"+ob->query("unit")+ob->query("name")+"��\n",me,this_object());
  command("nod");
  if (weapon) {
     msg+="����"+weapon->query("name")+"��";
     destruct(weapon);
  }
  msg+="װ��"+ob->query("name")+"��\n";
  ob->move(this_object());
  call_out("wield_weapon",1,msg,this_object(),ob);
  return 2;
}  

int wield_weapon(string msg,object me,object ob)
{
   if (!ob) return 1;
   ob->wield();
   message_vision(msg,me);
   return 1;
}   

void equip() 
{
  object weapon,me=this_object();
  string msg;

  switch (random(1)) {
    case 0: weapon=new("/d/qujing/jindou/obj/jindan");msg="$N�ӻ����ͳ���һЩ��ɰ��\n";break; 
//  switch (random(6)) {
//    case 0: weapon=new("/d/obj/weapon/hammer/baiyuban");msg="$N�ӻ����ͳ���һ�����塣\n";break; 
//    case 1: weapon=new("/d/obj/weapon/mace/bamboo");msg="$N˳�ִ����Ե�����������һ�ζ���\n";break; 
//    case 2: weapon=new("/d/obj/weapon/staff/shugan");msg="$N�ڵ��ϼ���һ�����ɡ�\n";break; 
//    case 3: weapon=new("/d/obj/weapon/stick/shuzhi");msg="$N���ִ���ߵ�С��������һ����֦��\n";break; 
//    case 4: weapon=new("/d/obj/weapon/sword/guishuzhi");msg="$NС������شӹ�����ժ��һ����֦��\n";break; 
//    case 5: weapon=new("/d/obj/weapon/whip/wuchou");msg="$N�ӻ�������һ������ͷ׵ĳ����\n";break; 
    default: weapon=new("/d/obj/weapon/");msg="$N\n";break; 
  }
  if (weapon->move(me))
  message_vision(msg,me);
  weapon->wield();
}

int accept_fight(object me)
{
  object ob=this_object(),target=query("target");

  if (me!=target) {
     message_vision("$N���$nһ�ۣ���м��˵��������������̫��Ҳ������档��\n",ob,me);
     return 0;
  }
  if (is_fighting()) 
     return ::accept_fight(me);
  message_vision("$N����$n��ȻһЦ��˵����������ֿɱ�̫���ˡ���������ˣ�������ʱ��ͣ(stop)����\n",ob,me);
  set_skills(me);
  set("mode","fighting");
  score=0;
  add_action("do_stop","stop");
//add_action("do_stop","surrender");
  add_action("do_throw","throw");
add_action("do_cut","cut");
add_action("do_cut","ti");

  kill_ob(me);
  set("starting_kee",me->query("kee"));
  return 1;
}

void heart_beat() 
{
  object me=this_object(),target=query("target");

  if (!target || environment(target)!=environment(me) ||
      !living(target)) {
    message_vision("$N���ĵ�̾�˿�����ת�����ˡ�\n",me);
    destruct(me);
    return;
  }
  if (is_fighting() && !query_temp("weapon")) equip();

  ::heart_beat();
}

void set_skills(object me) 
{
  mapping skill=me->query_skills();
  int max_value=10;
  string *skillnames;

  if (!skill) return;
  skillnames=keys(skill);
  for (int i=0;i<sizeof(skillnames);i++) 
     if(skill[skillnames[i]]>max_value)
        max_value=skill[skillnames[i]];
  
  set("max_force",me->query("max_force"));
  set("daoxing",me->query("daoxing"));
  set("combat_exp",me->query("combat_exp"));
  set("force",query("max_force"));
  set_skill("unarmed",max_value);
  set_skill("baihua-zhang",max_value);
  set_skill("parry", random(max_value));
  set_skill("dodge",random(max_value));
  set_skill("moondance",random(max_value));
  map_skill("dodge","moondance");
  map_skill("unarmed","baihua-zhang");
  set_skill("axe",random(max_value));
  set_skill("blade",random(max_value));
  set_skill("dagger",random(max_value));
  set_skill("fork",random(max_value));
  set_skill("hammer",random(max_value));
  set_skill("mace",random(max_value));
  set_skill("rake",random(max_value));
  set_skill("spear",random(max_value));
  set_skill("staff",random(max_value));
  set_skill("stick",random(max_value));
  set_skill("sword",random(max_value));
  set_skill("whip",random(max_value));
  set_skill("throwing",random(max_value));
}

varargs int receive_damage(string type, int damage, object who)
{
  if (type!="kee" || who!=query("target")) 
  return ::receive_damage(type,damage,who);
  call_out("hurt",1,this_object(),who);
  return ::receive_damage(type,damage,who);
}

void hurt(object ob,object me) 
{
  if (!ob || !me) return;
  if (!random(10)) {
    ob->command("surrender");
    ob->command("say ������ѣ�����������ô�أ����������в��У���������ˣ�");
    message_vision("$N�ݺݵذ���$nһ�ۣ�һת���������ˡ�\n\n",ob,me);
    remove_call_out("hurt");
    destruct(ob);
    return;
  }
  switch (random(6)) {
    case 0: ob->command("pain");break;
    case 1: ob->command("pain "+me->query("id"));break;
    case 2: ob->command("angry");break;
    case 3: ob->command("kick");break;
    case 4: ob->command("slogan "+me->query("id"));break;  
    case 5: ob->command("sign2");break;
  }
} 

void reset_action() 
{
  object me=this_object();
  mapping action;
  mapping new_act=([]);

  ::reset_action();
  if (!action=query("actions")) return;
  new_act=copy(action);
  if (new_act["post_action"]) 
  new_act["post_action"]= (: reward :);
  else new_act+=(["post_action" : (: reward :) ]);
  set("actions",new_act);
}

void reward(object me, object victim, object weapon,int damage) 
{
  int ammount=0;
  if (damage<=0) return;
  if (victim->is_busy()) return;
  if (victim->query_temp("no_move")) return;
  if (victim!=query("target")) return;
  score+=damage;
}

int do_stop() 
{
  object me=this_object(),target=this_player();
  object flower;

  if (target!=query("target")) return 0;
  if (!target->is_fighting(me)) 
    return notify_fail("����û�ڴ�ܡ�\n");

  message_vision("$N����Ȧ�⣬˵������������浽����ɡ���\n",target);
  me->remove_killer(target);
  target->remove_killer(me);
  me->remove_enemy(target);
  target->remove_enemy(me);
  command("ok");
  command("say лл�������棬���ж��ɻ�����ϲ���Ļ����͸���ɡ�");

  flower=new(__DIR__"obj/hua");
  flower->set("name",name);
//if (score>5000)
//    score=5000
  flower->set("score",random(score));
  flower->set("target",target);
  if (flower->move(target)) {
     message_vision("$N��$nһ��"+name+"��\n",me,target);
     command("smile");
   } else {
     target->command("norose");
     me->command(":P");
   }
   message_vision("$N˵������������ڡ���ƮȻ��ȥ��\n",me);
   destruct(me);    
   return 1;
}
  
int do_throw(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision("$N�ͳ����������˿����ӣ����Ĳ��㣬�ְѰ�������������\n",who,me);

  return 1;
}
int do_cut(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision("$N�ͳ��굶�����˿����ӣ����Ĳ��㣬�ְѰ�������������\n",who,me);

  return 1;
}
