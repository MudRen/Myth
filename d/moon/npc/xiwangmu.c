
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//xiwangmu.c
inherit NPC;
inherit F_MASTER;
string ask_tian();
string ask_mieyao();
string ask_cancel();
string avenge();
void create()
{
       set_name("����ĸ", ({"xi wangmu", "xi", "wangmu","master"}));
       set("long", "����������������������������ء�\n");
       set("title", "�¹���ʦ");
       set("gender", "Ů��");
       set("age", 100);
       set("class","xian");
       set("attitude", "friendly");
       set("rank_info/respect", "��̫̫");
       set("cor", 30);
       set("per", 30);
   set("looking", "��ɫ����������̬��");
       set("max_kee", 4500);
       set("max_gin", 800);
       set("max_sen", 4500);
       set("force", 4000);
       set("max_force", 2000);
       set("force_factor", 125);
       set("max_mana", 2000);
       set("mana", 4000);
       set("mana_factor", 100);
       set("combat_exp", 2000000);
       set_skill("literate", 220);
       set_skill("unarmed", 220);
       set_skill("dodge", 220);
       set_skill("force", 220);
       set_skill("parry", 220);
       set_skill("sword", 220);
       set_skill("spells", 220);
   set_skill("moonshentong", 220);
   set_skill("baihua-zhang", 180);
   set_skill("moonforce", 220);
   set_skill("snowsword", 200);
   set_skill("moondance", 150);
   map_skill("spells", "moonshentong");
   map_skill("unarmed", "baihua-zhang");
   map_skill("force", "moonforce");
   map_skill("sword", "snowsword");
   map_skill("parry", "snowsword");
   map_skill("dodge", "moondance");
   set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "mihun" :),
                (: cast_spell, "arrow" :)
        }) );
   set("inquiry", ([
          "����" : (: avenge :),
          "�����ѩ" : (: ask_tian :),
                           "����": (: ask_mieyao :),
]));
create_family("�¹�", 1, "��");
setup();

        carry_object("/d/obj/cloth/tianyi.c")->wear();
        carry_object("/d/ourhome/obj/shoes")->wear();
}
void init()
{
add_action("do_kneel","kneel");
}
string avenge()
{
    object who=this_player(),killer,where;
    string killid;
    if((string)who->query("family/family_name")!="�¹�")
        return ("�㲻�Ǳ��ɵ��ӣ��������Һθɣ�");
    if(who->query("faith")<1000)
        return ("���ڱ���������������������Ŭ�����С�");
    if(who->query("avenge/mud_age")>=who->query("death/mud_age"))
        return ("����δ����Ѷ");
    killid=who->query("kill/last_killer");
    if (! killer) return 0;
    killer=find_living(killid);
    if(!killer||!userp(killer))
        return ("������������һ��");
    command("say �������ȥΪ�㱧��");
    who->set("avenge/mud_age",who->query("mud_age"));
    where=environment(who);
    tell_room(where,"ֻ������ĸ�����һָ��\n");
    tell_room(where,"����������ڣ���ȥ��"+killer->query("name")+"ץ����\n");
    tell_room(environment(killer),"�������һֻ���ֽ�"+killer->query("name")+"ץ���ˡ�\n");
    killer->move(where);
    tell_room(where,killer->query("name")+"���ӿ�������������\n");
    command("say ������������ɱ�����¹�����");
    this_object()->kill_ob(killer);
    return("��������");
} 
void attempt_apprentice(object ob)
{
   if ( !((string)ob->query("gender")=="Ů��")){
      command("shake");
          command("say �����¹�ֻ��Ůͽ����λ" + RANK_D->query_respect(ob) + "��������߾Ͱɡ�\n");
      return;
   }

   if ( (string)ob->query("family/family_name")=="�¹�") {
   if (((int)ob->query("combat_exp") < 100000 )) {
   command("say " + RANK_D->query_respect(ob) +
"�ĵ��в��������Щ��ѧ�ط�������������\n");
   return;
   }
        command("pat "+ob->query("id"));
        command("say �ã�ϣ��" + RANK_D->query_respect(ob) +
"���Ŭ�����������¹�������\n");
       command("recruit " + ob->query("id") );
   return;
   }
   command("shake");
   command("say " + RANK_D->query_respect(ob) +
"������ȥѧЩ��������ɡ�\n");
        return;
}
int accept_fight(object me)
{
   return 0;
}
/*
int accept_object()
{
       object me=this_object();
       object who=this_player();
      object ob;
    if(ob->query("id")=="houyilove"){
     if (((string)who->query("family/family_name")=="�¹�")){
        who->set("kill_chang",1);
        write("����ĸŭ�������϶����ھ�Ȼ�����������˽�飡����������������
����Ȼ�����ŷ磬�ߣ���ȥ����ɱ���϶��ϸ���������!\n");
        call_out("destroy", 1, ob);
        return 1;
     }
     if (((string)who->query("family/family_name")!="�¹�")){
        command("say �ߣ����¹�����ʲôʱ���ֵ��������ܣ���");
        me->kill_ob(who);
       who->kill_ob(me);
      call_out("destroy", 1, ob);
                        return 1;
     }
   }
    if(ob->query("id")=="paper"){
     if (((string)who->query("family/family_name")=="�¹�")){
    who->set("kill_houyi",1);
        write("����ĸŭ�������϶����ھ�Ȼ�����������˽�飡����������������
����Ȼ�����ŷ磬�ߣ���ȥ����ɱ�˺���,�ϸ���������!\n");
        call_out("destroy", 1, ob);
        return 1;
     }
     if (((string)who->query("family/family_name")!="�¹�")){
        command("say �ߣ����¹�����ʲôʱ���ֵ��������ܣ���");
        me->kill_ob(who);
       who->kill_ob(me);
      call_out("destroy", 1, ob);
           return 1;
     }
   }
   else return 0;
}
void destroy(object ob)
{
        destruct(ob);
        return;
   }
*/
string ask_mieyao()
{
    object who=this_player();

    if((string)who->query("family/family_name")=="�¹�") {
      command("smile "+who->query("id"));
      return "/d/obj/mieyao"->query_yao(who);
    }
    return ("��������,�ι�����?\n");
}
int do_kneel()
{
    object who = this_player();
    if((string)who->query("family/family_name")!="�¹�")
     return notify_fail(this_object()->query("name")+"˵�����ֲ����ɼҵ��ӣ����Ҹ�ʲô��\n");
   if("/d/obj/mieyao"->delete_mieyao(who)){
        command("say ��Ȼ��ˣ������˰ɣ�������û��������񣬵���Щ�ͷ���\n");
	who->add("faith",-5);
        message_vision("$N���ҳ϶��½��ˣ�\n",who);
     }
}
string ask_tian()
{
    object who=this_player();
    if((string)who->query("family/family_name")!="�¹�")
        return ("�㲻�Ǳ��ɵ��ӣ���ô�����������ѩ?");
    if(who->query("faith")<1000)
        return ("���ڱ���������������������Ŭ�����С�");
    who->set_temp("moon_tian",1);
        return ("�����perform tian,Ҳ���Գ���perform mantian��");
}
 
string ask_cancel()
{
    object me=this_player();
//lost add
//  if((int)me->query_temp("m_mieyao"))
  if(me->query("secmieyao"))
{
      me->add("daoxing",-2000);
      //lost add
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

