
inherit NPC;
inherit F_MASTER;
//string expell_me(object me);
string ask_mieyao();
string ask_cancel();
void create()
{
  set_name("����", ({ "qin qiong", "qin", "shubao", "qiong", "qin shubao", "master", "shifu" }));
  set("title", "����Ԫѫ");
  set("gender", "����");
  set("age", 43);
  set("str", 30);
  set("per", 26);
  set("int", 30);
  set("cor", 50);
  set("cps", 50);
  set("long", "���屦�Ǵ��ƹ���������������һλ�������佫��\n");
  set("combat_exp", 1200000);
  set_skill("literate", 120);
  set_skill("spear", 120);
  set_skill("force", 120);
  set_skill("dodge", 180);
  set_skill("parry", 150);
  set_skill("xuanyuan-archery",180);
  set_skill("mace", 200);
  set_skill("archery", 150);
  set_skill("wusi-mace", 180);
  set_skill("yanxing-steps", 150);
  set_skill("bawang-qiang", 100);
  set_skill("lengquan-force", 120);
  set_skill("unarmed", 160);
  set_skill("changquan", 120);
  map_skill("mace", "wusi-mace");
  map_skill("force", "lengquan-force");
  map_skill("unarmed", "changquan");
  map_skill("spear", "bawang-qiang");
   map_skill("archery", "xuanyuan-archery");
  map_skill("parry", "bawang-qiang");
  map_skill("dodge", "yanxing-steps");
  set("max_sen", 2800);
  set("max_kee", 4400);
  set("force", 2000);
  set("max_force", 1800);
  set("force_factor", 80);
  set("inquiry", ([
		   "name": "�����������屦��",
		   "here": "������ǽ����������ѵ��㲻֪����",
		   "rumors": "���²��ڽ������ߺܾ��ˣ������ϵ��������¿ɲ�̫�����",
//		   "תҵ": (: expell_me :),
//		   "leave": (: expell_me :),
                 "��ħ": (: ask_mieyao :),
		   ]) );

  create_family("������", 2, "��");
  set("chat_chance_combat", 60);
  set("chat_msg_combat", ({
		(: perform_action, "spear", "qiangjian" :),
  }) );

  setup();
carry_object("d/obj/weapon/archery/zhentian-arrow")->wield();
  carry_object("/d/obj/armor/tiejia")->wear();
  carry_object("/d/obj/weapon/mace/copperjian");
}

string ask_mieyao()
{
  object me=this_player();
  if(me->query("family/family_name")!="������")
     return ("�㲻�Ǳ������ˣ�");
  command("smile "+me->query("id"));
  return "/d/obj/mieyao"->query_yao(me);
}
int accept_fight(object me)
{
  command("say �Ϸ��δ�ͽ����˶��ֹ����ˣ�����Ҳ����������\n");
  return 0;
}
int attempt_apprentice(object me)
{
  string myname=RANK_D->query_respect(me);
  if ((int)me->query("combat_exp")< 100000)
    {
      command("say ��λ"+myname+"������ȥ�������ҽ��������ɣ�");
      return 0;
    }
  command("haha");
  command("say �ܺã�ʱ����������֮�ʣ�"+myname+"���Ŭ�������ձض��гɡ�\n");
  command("recruit " + me->query("id") );
  return 1;
}
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob) )
    ob->set("class", "fighter");
}
int prevent_learn(object me, string skill)
{
  string myname=RANK_D->query_respect(me);

  if (me->query("combat_exp") < 100000)
    {
      command("emote ������üͷ��˵����"+myname+"��Ƿ�������Ϸ�����"+myname+"����������⡣");
      return 1;
    }
  return 0;
}

string expell_me(object me)
{
  me=this_player();
  if((string)me->query("family/family_name")=="������")
    {
      me->set_temp("betray", 1);
      command("sigh");
      return ("���Ҵ����ɷ���ȴ���ܷ������Ը��(agree)��");
    }
  return ("ȥ����Ԭ�����ɣ�������֪����");
}
void init()
{
  add_action("do_agree", "agree");
}
int do_agree(string arg)
{
//  if(this_player()->query_temp("betray"))
  if(this_player()->query_temp("betray") && this_player()->query("family/family_name")=="������")
// modified by tree.2001/7/10
    {
      message_vision("$N���������Ը�⡣\n\n", this_player());
      command("say �����ȥ�ɣ������ն񣬺���Ϊ֮������");
      this_player()->add("betray/count", 1);
      this_player()->add("betray/jjf", 1);
      this_player()->set("combat_exp", this_player()->query("combat_exp")*80/100);
      this_player()->delete("family");
      this_player()->delete("class");
      this_player()->set("title", "��ͨ����");
      this_player()->set_temp("betray", 0);
      this_player()->save();
      return 1;
    }
  return 0;
}

string ask_cancel()
{
    object me=this_player();
// lost add
//150  if((int)me->query_temp("m_mieyao"))
    if((int)me->query("secmieyao")) 
{
      me->add("daoxing",-2000);
     me->add("m_fangqi",1);
       me->delete("secmieyao_mudage");  
      me->delete_temp("m_mieyao");
      me->delete("secmieyao");
      me->delete("secmieyao/type");
      me->delete("secmieyao/location");
      me->delete("secmieyao/place");
      me->delete("secmieyao/name");
      me->delete("secmieyao/id");
     return ("û�õĶ�����");
}
else
{
     return ("���������𣿣�");
}
}

