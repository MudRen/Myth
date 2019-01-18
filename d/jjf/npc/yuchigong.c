//created 5-20-97 pickle
 
inherit NPC;
inherit F_MASTER;

void create()
{
  set_name("ξ�ٹ�", ({"yuchi gong", "yuchi", "gong", "yuchigong", "jingde", "yuchi jingde", "yuchijingde", "master", "shifu"}));
  set ("long", @LONG
ξ�ٹ����־��£�������̫�������ͽ�����Ϊ����ʱ��
ʮ�����ú���������Ƿ��������ݵ�ǰԪ˧���������
���ơ�����ʹһ�����ǹ����ϲʹһ�Դ�����ڸֱޡ�
LONG);
 
  set("title", "����Ԫѫ");
  set("gender", "����");
  set("age", 43);
  set("str", 45);
  set("per", 15);
  set("int", 20);
  set("cor", 50);
  set("cps", 40);
  set("combat_exp", 1400000);
  set_skill("spear", 120);
  set_skill("force", 150);
  set_skill("dodge", 150);
  set_skill("parry", 120);
  set_skill("mace", 180);
  set_skill("jinglei-mace", 150);
  set_skill("yanxing-steps", 120);
  set_skill("bawang-qiang", 100);
  set_skill("lengquan-force", 150);
  set_skill("unarmed", 120);
  set_skill("changquan", 100);
  map_skill("mace", "jinglei-mace");
  map_skill("force", "lengquan-force");
  map_skill("unarmed", "changquan");
  map_skill("spear", "bawang-qiang");
  map_skill("parry", "jinglei-mace");
  map_skill("dodge", "yanxing-steps");
  set("max_sen", 1500);
  set("max_kee", 4000);
  set("force", 1000);
  set("max_force", 2500);
  set("force_factor", 100);
 
  create_family("������", 2, "��");
  setup();
 
  carry_object("/d/obj/weapon/spear/gangqiang");
  carry_object("/d/obj/weapon/mace/malemace")->wield();
  carry_object("/d/obj/armor/tiejia")->wear();
}
 
int accept_fight(object me)
{
  command("say �Ϸ����أ��������˷��������ˡ�\n");
  return 0;
}
int attempt_apprentice(object me)
{
  string myname=RANK_D->query_rude(me);
  int kar=me->query_kar();
  int effstr=(int)(me->query("str")+me->query_skill("unarmed",1)/10-2);

  if ((effstr< 20) || (int)me->query_con()<25)
    {
      command("say ��"+myname+"���޸���֮������������ͽ�ܣ�");
      return 0;
    }
  if ((int)me->query("cps") < 20 && (int)me->query_cor()<20)
    {
      command("say ��"+myname+"���ӻ�����ֻ����");
      return 0;
    }
  command("say Ҫ�����Ϊʦ����Ҳ���ѡ�ֻ�轫������¥���˾��У�\n");
  me->set("pending/jjfbaiξ�ٹ�", 1);
  return 1;
}
int accept_object(object me, object ob)
{
  string myname=RANK_D->query_rude(me), thing=(string)ob->query("id");
  object book, npc=this_object();
  int kar=me->query_kar(), diff;
 
  if ((string)ob->query("name_recognized")!="����¥����")
    {
      command ("say ����ʲô���ã�");
      call_out("dropthing", 1, thing);
      return 1;
    }
  if (me->query("pending/jjfbaiξ�ٹ�"))
    {
      command ("nod");
      command ("say "+myname+"��Ȼ�������ӣ��Ϸ��������ɣ�");
      me->delete("pending/jjfbaiξ�ٹ�");
      command ("recruit " + me->query("id") );
      call_out("destroy", 1, ob);
      return 1;
    }
  else
    {
      call_out("destroy", 1, ob);
      if (!me->query("mark/jjf��κ������"))
	  {
	    command("hehe");
	    command("say ������ӿ�����������İɣ�");
	    command("say ��ƾ����㱾�£�Ҳ�ҵ�������¥��");
	    return 1;
	  }
      command ("thumb" +me->query("id"));
      command ("say "+myname+"��Ȼ�������ӣ�");
      diff=35-kar;
      if(random(diff*diff)>4)
	return 1;
      command("say ����"+myname+"���Ϸ���Ե�������ְ��ҳ���һ�ڶ�����");
      command("say �Ȿ�����Ϸ����Ĳ����ؾ����͸���ɣ�");
      book=new("/d/obj/book/parrybook2");
      message_vision(npc->query("name") + "��$Nһ��"+book->query("name"), me);
      book->move(me);
      return 1;
    }
}
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob) )
    ob->set("class", "fighter");
}
void destroy(object ob)
{
  destruct(ob);
  return;
}
void dropthing(string thing)
{
  command("drop "+thing);
  return;
}













