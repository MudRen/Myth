//����ɽ���ɡ�dhxy-evil 2000.7.5
// Modified by Longer@ALL_XYJ 2001-12-19

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string expell_me(object me);
string ask_mieyao(object me);
string ask_cancel();
void create()
{
       set_name("��ʥ", ({ "jian sheng", "sheng", "swordsman" }));
        set("title","");
        set("long", 
"��ɽ������ʦү����ͷ�׷������ˣ����۾�������\n");

        set("gender", "����");
        set("age", 65);
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 40);
        set("con", 30);
        set("per", 20);
        set("class","swordsman");
        
        set("kee", 4000);
        set("max_kee", 4000);
        set("sen", 3000);
        set("max_sen", 3000);
        set("force", 8000);
        set("max_force", 5000);
        set("max_mana",5000);
        set("mana",8000);
        set("force_factor", 100);
        set("mana_factor", 100);
        set("combat_exp", 3000000);
        set("daoxing", 5000000);

        set_skill("spells",220);
        set_skill("force", 220);
        set_skill("dodge", 220);
        set_skill("parry", 220);
        set_skill("sword", 220);
        set_skill("zixia-shengong", 220);
        set_skill("sevensteps", 180);
        set_skill("hunyuan-zhang", 220);
        set_skill("literate", 180);
        set_skill("unarmed", 220);
        set_skill("mindsword", 200);
set_skill("yujianshu", 200);
        set_skill("taoism",220);
        map_skill("spells", "taoism");
        map_skill("dodge", "sevensteps");
        map_skill("force", "zixia-shengong");
        map_skill("parry", "mindsword");
        map_skill("sword", "yujianshu");
        map_skill("unarmed", "hunyuan-zhang");


        create_family("��ɽ����", 4, "������");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "sword","fenguang" :),
                (: cast_spell, "jianshen" :),                
        }) );
   add_temp("apply/damage", 135);
   add_temp("apply/attack", 135);
   add_temp("apply/dodge", 135);
   add_temp("apply/spells", 100);
   add_temp("apply/armor", 150);
   add_temp("apply/armor_vs_force",250);
   add_temp("apply/armor_vs_spells",250);
  set("inquiry", ([
        "leave": (: expell_me :),
    "����": (: ask_mieyao :),
      "cancel": (: ask_cancel :),
        ]) );
        setup();
        
        carry_object("/d/obj/cloth/jinpao")->wear();
        carry_object("/d/shushan/obj/qxsword")->wield();
}
void attempt_apprentice(object ob)
{        
	if (ob->query_skill("sword",1) < 130) {
        command("say ����ɽ���ɣ���ע�������������У����ҿ�" + RANK_D->query_respect(ob) + "�ǲ��Ǹö����¿๦�أ�");
                return ;
        }
        if ((int)ob->query_int() < 35) {
        command("say ���ҿ�" + RANK_D->query_respect(ob) + "�������ƺ����ʺ�ѧ����ɽ�����书��");
                return;
        }
        /*
        if (ob->query("shushan/ask_zuidao_go")) {
        if (ob->query("nyj/shushan")!="done"){
                command("say " + RANK_D->query_respect(ob) + "�����ȻҪΥ���Ź�ȥ�������������Ҹ��ҽ�ʥѧ��ɽ�����书��");
                return;
        }
        command("say ���⣬�������⣡");
        
        }*/
        command("say �ðɣ��Ҿ��������ˡ�");
        command("recruit " + ob->query("id"));
        ob->set("class", "swordsman");
        ob->set("title",HIY"��ʥ����"NOR);
}
string expell_me(object me)
{
  me=this_player();
  if((string)me->query("family/family_name")=="��ɽ����")
    {
      me->set_temp("betray_shushan", 1);
      command("sigh");
      return ("������ɽ�Ź棬���ɵ��书���˲��ܴ��ߣ����Ը��(agree)��");
    }
  return ("�Ҳ�֪����");
}
void init()
{
  add_action("do_agree", "agree");
}
int do_agree(string arg)
{
  if(this_player()->query_temp("betray_shushan"))
    {
      message_vision("$N���������Ը�⡣\n\n", this_player());
      command("say �����ȥ�ɡ����������������⣡");
      this_player()->add("betray/count", 1);
      this_player()->add("betray/shushan", 1);
      this_player()->delete_skill("taoism");
    this_player()->delete_skill("zixia-shengong");
    this_player()->delete_skill("shushan-jianfa");
      this_player()->delete_skill("mindsword");
//    this_player()->delete_skill("dugu-jiujian");
    this_player()->delete_skill("yirubian");
      this_player()->delete_skill("jingya-sword");
      this_player()->delete_skill("yujianshu");
      this_player()->delete_skill("sevensteps");
      this_player()->delete_skill("hunyuan-zhang");
      this_player()->delete_skill("fumozhang");
      this_player()->delete_skill("canxin-jian");
      message_vision("��ʥ��$N��ͷ������һ�£�$N��ʱ����������ʧ��\n\n", this_player());
      this_player()->delete("family");
      this_player()->delete("class");
      this_player()->set("title", "��ͨ����");
      this_player()->save();
      return 1;
    }
  return 0;
}
string ask_cancel()
{
    object me=this_player();
// lost add
//155  if((int)me->query_temp("m_mieyao"))
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
string ask_mieyao(object me)
{
    me=this_player();
     if((string)me->query("family/family_name")=="��ɽ����") {
//  if(me->query("faith")<100)
//      return ("�㻹���ȶ������Ϊ�");
    tell_room(environment(me),"��ʥ�����д�.....\n");
    return "/d/obj/mieyao"->query_yao(me);
}
     return ("ƶ����֪��");
}


