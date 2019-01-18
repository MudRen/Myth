// guanjia.c
// 9-2-97 pickle

inherit NPC;
inherit F_MASTER;
string expell_me(object me);
void create()
{
  set_name("����", ({"tian shu", "tian", "shu", "tianshu", "monster"}));
  set("gender", "Ů��");
  set("age", 23);
  set("long",
"�������޵׶��Ĵ�ܼҡ��뵱����������һ�����ɳ������Σ�\n"
"��������̫��������վ����������չ��ŵ���Ľ��飬����\n"
"�����������ⶴ�Ĺܼҡ�\n");
  set("title", "��ܼ�");
  set("cor", 25);
  set("combat_exp", 200000);
  set("daoxing", 400000);

  set("attitude", "heroic");
  create_family("�ݿ�ɽ�޵׶�", 2, "����");
  set_skill("literate", 10);
  set_skill("unarmed", 55);
  set_skill("parry", 55);
  set_skill("spells", 55);  
  set_skill("sword", 55);  
  set_skill("qixiu-jian", 55);
  set_skill("yinfeng-zhua", 55);
  set_skill("lingfu-steps", 55);
  set_skill("dodge", 55);
  set_skill("force", 55);
  set_skill("yaofa", 55);
  set_skill("huntian-qigong", 55);
  map_skill("force", "huntian-qigong");
  map_skill("unarmed", "yinfeng-zhua");
  map_skill("spells", "yaofa");
  map_skill("sword", "qixiu-jian");
  map_skill("parry", "qixiu-jian");
  map_skill("dodge", "lingfu-steps");
  
  set("str", 30);
  set("per", 30);
  set("max_kee", 300);
  set("max_sen", 300);
  set("force", 350);
  set("max_force", 350);
  set("force_factor", 20);
  set("mana", 550);
  set("max_mana", 500);
  set("mana_factor", 25);
  set("inquiry", ([
                   "����": (: expell_me :),
                   "leave": (: expell_me :),
		   "name": "������������޵׶��Ĵ��ܹܣ�",
		   "here": "��Ϲ��������������Ƕ����������ݿ�ɽ�޵׶���",
		   "rumors": "��֪�����ұ�����ȥ��",
		   "�������": "��Ϲ���������������ֲ��ǳ��ӣ�",
                 ]) );  
  setup();
  carry_object("/d/obj/weapon/blade/blade.c")->wield();
  carry_object("/d/obj/cloth/yuanxiang")->wear();
  carry_object("/d/obj/cloth/nichang")->wear();
}
int attempt_apprentice(object me)
{
  string myname=RANK_D->query_rude(me);
  string myid=me->query("id");
  command("look "+myid);
  command("consider");
  if (me->query("combat_exp")+me->query("daoxing")>400000)
  {
    command("say "+myname+"����ʲô�������������λ�ӣ�\n");
    return 1;
  }
  if (me->query("wudidong/sell_reward")<1000)
  {
    command("say "+myname+"Ҫ�����޵׶������Ἰ����ͷ��Т���ң�\n");
    return 1;
  }
  command("grin");
  command("say ���������������ˡ�"+myname+"�����˶������Ū��ԭ�ϣ�");
  command("recruit "+myid);
  return 1;
}
int prevent_learn(object me, string skill)
{
  string myname=RANK_D->query_rude(me);

}
string expell_me(object me)
{
  me=this_player();

  if((string)me->query("family/family_name")=="�ݿ�ɽ�޵׶�")
  {
    me->set_temp("wudidong/betray", 2);
    return ("ʲô����Ҫ�뿪������ͱ������ͷ����ҽ�Ҫ�ջ����ȫ�������书��(jieshou)\n");
  }
  return ("�����������ģ�����\n");
}
void init()
{
    add_action("do_accept", "jieshou");
}
int do_accept(string arg)
{
    object me=this_player();
    if (arg) return notify_fail("��Ҫ��ʲô��\n");
    if (!me->query_temp("wudidong/betray")) return notify_fail("��Ҫ����ʲô��\n");
    message_vision("$N����������Ҫ�뿪�޵׶�������ѣ�\n", me);
    me->add("betray/count", 1);
    me->add("betray/wudidong", 1);
    me->delete("family");
    me->delete("class");
    me->set("title", "��ͨ����");
    me->add("combat_exp", -(me->query("combat_exp")/5));
    me->add("daoxing", -(me->query("daoxing")/5));
    if (me->query_skill("yaofa"))
    {
        me->delete_skill("yaofa");
    }
    if (me->query_skill("huntian-qigong"))
    {
        me->delete_skill("huntian-qigong");
    }
        me->delete_skill("huoyun-qiang");
        me->delete_skill("dao");
        me->delete_skill("kugu-blade");
        me->delete_skill("throwing");
        me->delete_skill("stealing");
        me->delete_skill("lingfu-steps");
        me->delete_skill("qixiu-jian");
        me->delete_skill("yinfeng-zhua");
    me->save();
    return 1;
}
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob))
  {
    ob->set("class", "yaomo");
  }
}
�
