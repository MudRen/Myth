// created by angell 1/1/2001

inherit NPC;
int say_zhu();
int test_jing(object ob);
void announce_start();
void announce_finish(object ob);

void create()
{
  set_name("�鼪����", ({"lingji pusa", "pusa"}));
  set("long", "һλ��ü��Ŀ�����ˣ���˵������ǿ��
�ڴ���Ժ�����������ɻ����ˡ�\n");
  set("gender", "����");
  set("age", 80);
  set("attitude", "friendly");
  set("combat_exp", 2000000);
  set("per", 100);
  set_skill("dodge", 200);
  set_skill("force", 200);
  set_skill("spells",190);
  set_skill("unarmed",200);
  set_skill("buddhism", 190);
  set_skill("jienan-zhi", 200);
  set_skill("lotusmove", 160);
  set_skill("lotusforce",180);
  map_skill("force","lotusforce");
  map_skill("unarmed", "jienan-zhi");
  map_skill("dodge", "lotusmove");
  map_skill("spells", "buddhism");
  set("max_sen",3000);
  set("max_gee",3000);
  set("max_gin",3000);
  set("force",3000);
  set("max_force",3000);
  set("max_mana",3000);
  set("mana",3000);
  set("force_factor",175);
  set("mana_factor",100);
  set("chat_chance_combat", 60);
  set("chat_msg_combat", ({
	(: cast_spell, "bighammer" :),
        }) );
   set("inquiry",([
		  "��": (: say_zhu :),
		  "������": (: say_zhu :),
                "zhu":(: say_zhu :),
                "name":"�����鼪��",
		  "here": "���������Ľ����ĵط���С����ɽ��",
		  "rumors":"˵�����������ĵĶ����龹�����ֵ���ȥ��",
                "��ħ":(:test_jing:),
                "book":(:test_jing:),
		  ]));

  setup();

  carry_object("/d/huangfeng/obj/jiasha")->wear();
}

int say_zhu()
{
  object  me=this_player();
  
  if (me->query("obstacle/huangfeng") == "done")
	message_vision("��$N����һл���Ե�����ʩ�����ģ������ѽ������������ˣ������ٶ�����\n",me);
    else
	{
	command("sigh");
	command("say ����ǰ�����ǹ�һ����������ȥ����˵�������Ǻ�԰֮���ˡ�\n");
	}
return 1;
}

void announce_start()
{
    command("chat ��λʩ�����ˣ�");
    command("chat ��ħ����������������λ��Ե��ǰ��һ�ԡ�");
}

void announce_finish(object ob)
{
  ob->delete("fumo2_gived");
  remove_call_out("announce_finish");
  command("chat ��ħ��¼������һ���ֻس�����������ʱ��λʩ��ǰ��һ�ԣ�");
}

int test_jing(object ob)
{     
   object who=this_player();
   object book;
   object where=environment();
      
      if(ob->query("fumo2_gived")) {
          command("sigh "+who->query("id"));
      message_vision("$N̾Ϣ������ʩ�������ˣ���ħ��¼�Ѿ�������Ե���ˣ�ֻ�ܵ���һ�Σ�\n",ob);
             return 1;
          }
   if(!where->query("book_give_can")) {
      message_vision("$NЦ����ʱ��δ������λʩ���ҵ�ƶɮ��������,�������٣�\n",ob);
             return 1;
      }
   if(who->query_skill("force", 1) < 100 ) {
    message_vision("$N΢��˫�ۣ�̾�˿�������λʩ���Է�ħ�ķ������򻹲�����򣬿��½�������ħ��\n", ob,who);
           return 1;
      }
   if (who->query("fumo2") ) {
     message_vision("$N���Ƶ���ʩ���Ѿ���ù������ˡ�Ե��һ˵ʵ��������������������Ҳ��ʩ����ذɣ�\n", ob);
           return 1;
      }
   book=new("/d/obj/book/forcebook2");
   book->move(who);
       who->set("fumo2", 1);
     ob->set("fumo2_gived",1);
     where->delete("book_give_can");
       message_vision("$N�ӻ���ȡ������ħ�ľ��ݸ�$n��΢Ц��������ʩ���������У���ħ������\n", ob,who);
     command("chat "+who->query("name")+"ʩ����Ե��񣬻�÷�ħɽ�ľ�һ����");
     remove_call_out("announce_finish");
     call_out("announce_finish",600,ob);
     return 1;
}

void call_out_announce_success(object who)
{
	call_out("say_hi",1,who);
	call_out("announce_success",2,who);
}

void say_hi(object who)
{
  message_vision ("\n����У��鼪������$N΢Ц��л��\n",who);
}

void die()
{
      int i;
      object *inv;
        object me=this_object(); // mudring Oct/11/2002

    if( environment() ) {
             message("sound", "\n�鼪����ҡͷ̾������δ�ã���ȥ��ȥ,�����ӷ�\n\n", environment());
             command("sigh");
             message("sound", "\n�鼪����Ծ�ϰ�צ�����������ƶ�������ȥ�ˡ�����\n\n", environment());
    inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++)
              {
	     if (inv[i]->query("no_drop")) continue;
                 inv[i]->move(environment(me));
	   }
          }
      destruct(me);
 }

void unconcious()
{
	die();
}

void announce_success (object who)
{
  int i;
  object zhu;
  if (who->query("combat_exp") < 100000)
   {
     message_vision("����У��鼪��������$N̾�˿��������в�����������Ȼ��\n",who);
     return;
   }
  if (who->query("obstacle/huangfeng") == "done")
       return;
  if (who->query_temp("obstacle/huangfeng_zhu_getted")==0)
    return;
  if( !(zhu = present("dingfeng zhu", who)) ) 
       return;
  if (who->query_temp("obstacle/huangfeng_huangfengguai_killed")==0)
    return;
  i = random(500);
  message_vision("����У��鼪��������һ�У��������$N�����ƿն�ȥ�����ȵĶ������������С�\n",who);
   destruct(zhu);
  who->delete_temp("obstacle/huangfeng_zhu_getted");
  who->add("obstacle/number",1);
  who->set("obstacle/huangfeng","done");
  who->add("combat_exp",i+4000);
  command("chat "+who->query("name")+"�Ʒ��뽵���Ʒ�֣�Ϊ����Ѱ�ض����飡");
  command("chat "+who->query("name")+"˳������������һ�أ�");
  tell_object (who,"��Ӯ����"+chinese_number(4)+"��"+
               chinese_number(i/4)+"��"+
               chinese_number((i-(i/4)*4)*3)+"ʱ���ĵ��У�\n");
  who->save();
}

