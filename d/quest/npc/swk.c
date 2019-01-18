// demongorgon.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name( HIW "�����" NOR, ({ "sun xingzhe","swk","sun","xinzhe" }) );
	set("long",
		"һ��������ߣ����ݸɸɣ������ë�������\n");

	set("age", 30);
        set("title", HIY"��ͽ��"NOR);
	set("max_gin", 3000);
	set("max_kee", 3000);
	set("max_sen", 3000);

	set("max_atman", 3000);
	set("atman", 3000);
      set("max_force", 5000);
      set("force", 10000);
      set("max_mana", 5000);
      set("mana", 10000);

	set("str", 40);
	set("cor", 40);
	set("cps", 40);
	set("spi", 40);
	set("int", 40);
	set("con", 40);
	set("kar", 40);
	set("per", 40);

	set("combat_exp", 3500000);
	set("daoxing", 2000000);

	set_skill("unarmed", 250+random(50));
        set_skill("dodge", 250+random(50));
        set_skill("parry", 250+random(50));
	set_skill("stick", 250+random(50));
	set_skill("spells", 250+random(50));
	set_skill("dao", 250+random(50));
	set_skill("puti-zhi", 250+random(50));
	set_skill("wuxiangforce", 250+random(50));
	set_skill("force", 250+random(50));
	set_skill("qianjun-bang", 250+random(50));
	set_skill("jindouyun", 250+random(50));
	
	map_skill("spells", "dao");
	map_skill("unarmed", "puti-zhi");
	map_skill("force", "wuxiangforce");
	map_skill("stick", "qianjun-bang");
	map_skill("parry", "qianjun-bang");
	map_skill("dodge", "jindouyun");
        set("force_factor",300);	
        set("mana_factor",300);
        set("bellicosity",300);
        set("nk_gain", 100+random(50));
        set("nk_factor", 12);

	set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
		(: cast_spell, "light" :),
		(: cast_spell, "dingshen" :),
                (: cast_spell, "thunder" :)
        }) );

	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/armor", 250);
	set_temp("apply/damage", 250);

	setup();

	carry_object("/d/obj/weapon/stick/fake-jingubang")->wield();
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
}


void init()
{
  ::init();
  add_action("do_no", "fight");
  add_action("do_no", "kill");
  add_action("do_no", "steal");
  add_action("do_no", "cast");
  add_action("do_no","ji");
  add_action("do_no","throw");
  add_action("do_block","",1);
  call_out("leave",20);   
}

void leave()
{
      object me = this_object(); 
      object where = environment (me);
      object ts = present ("tang sanzhang", where);
      object ts2 = find_living("tang sanzhang");
  
      
      if (!ts2)
       {   
        command("say ʦ����û�ˣ��һ��ǻػ���ɽȥ�ˡ�����");
        message("vision",HIB + name() + "һ���̵����ˡ�\n" NOR,environment());
        remove_call_out("leave");
        destruct(this_object());
        return ;
       }else{
       
        if(!ts) 
         {  command("say �ҵ�����ʦ��ȥ�ˡ�����");
            message("vision",HIB + name() + "һ���̵����ˡ�\n" NOR,environment());
            if (environment(ts2))
               { 
               	   me->move(environment(ts2));
               }else{
                   remove_call_out("leave");
                   destruct(this_object());
                   return ;
                }   
                   
          }    
       	}
       
   remove_call_out("leave");
   call_out("leave",5); 
   return;
}

int do_no(string arg)
{
  object who = this_player();
  object me = this_object();


  if (arg!="tang sanzhang"&&who->query_temp("qujing_kill")!=1)
  {
      message_vision("$N������첻֪���ʲô��$n����Ķ���$N��\n",who,me);
     return 1;
 
  }
  return 0;
}

void die ()
{
        object me = this_object();
        message_vision ("\n$N��ͷ����,���ܱߺ�:  ���Ȼػ���ɽȥ��......\n",me);
        load_object("/obj/empty");
        me->move("/obj/empty");
        call_out ("destruct_me",3,me);
  
}

void destruct_me (object me)
{
  destruct (me);
}

void unconcious()
{
   die();
 }


int do_block(string arg)
{
    object me=this_object();
    object who=this_player();
    string verb=query_verb();
    int t;
    
    // wizardp(who) && 
    
    if(!userp(who)) return 0;
       
      
    if(who->query_temp("qujing_kill")==0) return 0;
       
    if(verb!="go" &&
            verb!="fly" &&
            !(environment() && environment()->query("exits/" + verb)))
        return 0;
    
    t= random(2);
   
    if (t==1) {
        
        message_vision("$n��$Nһ����ע�⣬��æ���˹�ȥ��\n",me,who);
        return 0;
    }
   
        message_vision("$N�𹿰�һ������$n��ǰ�������е���\n"+
                " �����֣�����������������,�������ɣ�\n\n",me,who);
        tell_object(who,me->name()+"һ����ס���㣡\n");
         return 1;
}

void kill_ob (object ob)
{
  ob->set_temp("qujing_kill",1);
  ::kill_ob(ob);
}

void heart_beat()
{
        if (!query_temp("weapon") && !query_temp("added"))
        {
        set_temp("added", 1);
        set("force_factor",100);
        set("force",2000);
        }
        if (query("eff_kee")<query("max_kee"))
        {
        if (random(10))
        command("eat yao");

        else
        {
                command("surrender");
                call_out("exertheal",1,this_object());
        }
        }


        ::heart_beat();
}
varargs int receive_damage(string type, int damage, object who)
{
  object me=this_object();
  call_out("exertheal",1,me);
  return ::receive_damage(type,damage,who);
}

void exertheal(object me) 
{
  me->command("exert recover");
}

