//girl.c
#include <ansi.h>

inherit NPC;
string ask_for_shuizhu();
void check_player();
void create()
{
       set_name("������", ({"li yiru","li"}));
       set("long", "������������ң������ʥŮ�������Ů����Ϊ������ȥ��������
���̣������Ϊ�����������硣\n");
       set("gender", "Ů��");
       set("age", 16);
       set("attitude", "friendly");
       set("shen_type", 1);
       set("per", 40);
       set("int", 40);
       set("str", 40);
       set("cps", 40);
       set("spi", 40);
       set("max_kee", 3000);
       set("max_gin", 3000);
       set("max_sen", 3000);
       set("force", 6000);
       set("max_force", 3000);
       set("force_factor", 200);
       set("max_mana", 5000);
       set("mana", 10000);
       set("mana_factor", 150);
       set("combat_exp", 5000000);
       set_skill("literate", 90);
       set_skill("unarmed", 200);
       set_skill("dodge", 220);
       set_skill("parry", 220);
 set_skill("sword", 220);
 set_skill("spells", 220);
 set_skill("moonshentong", 220);
 set_skill("baihua-zhang", 220);
 set_skill("moonforce", 220);
 set_skill("force", 220);
 set_skill("snowsword", 220);
 set_skill("moondance", 220);
 map_skill("spells", "moonshentong");
 map_skill("unarmed", "baihua-zhang");
 map_skill("force", "moonforce");
 map_skill("sword", "snowsword");
 map_skill("parry", "snowsword");
 map_skill("dodge", "moondance");
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: cast_spell, "arrow" :),
                (: cast_spell, "mihun" :),
                (: perform_action, "sword.huifeng" :),
                (: perform_action, "sword.wuxue" :),
        }) );
        set("inquiry", ([
  "����ң" : "�����Ҹ��ף��������ڳ�ȥ�ˣ�",
  "�����" : "���ҵ����ף��Ҹճ�������ȥ���ˡ�",
  "ˮ����" : (: ask_for_shuizhu :),
  ]) );
        setup();
        carry_object("/d/obj/weapon/sword/changjian")->wield();
        carry_object("/d/obj/baowu/shuizhu");
}
void init()
{
add_action("do_agree","yes");
        check_player();
}
string ask_for_shuizhu()
{
        object who = this_player();
if(!present("shuizhu",this_object()))
  return "�Բ���,ˮ�����Ѿ�����������!\n";
if(who->query("search_for_mujian"))
  return "����Ҫ������ľ��������?\n";  
        if(who->query("asked_for_shuizhu") || who->query("liyiru/kill_jiaolong"))
            return "����Ҫ����ȥ��ѵ��ѵˮ̶���������\n";
        command("say ����Ҳ�С�����....\n");
        command("xixi "+who->query("id"));
        command("say ���Ȱ��ҽ�ѵһ��ˮ̶������֣��ԴӸ��׳�ȥ��\n
�������ȥ�����ˡ�\n");
        who->set("asked_for_shuizhu",1);
return "��ͬ��(yes)�𣿺�Σ�յģ�";
}
int do_agree()
{
 object who = this_player();

        if(!who->query("asked_for_shuizhu"))
           return notify_fail("��Ҫ��Ӧʲô����\n");
        who->delete("asked_for_shuizhu");
        if(who->query("combat_exp")<1000000)
           return notify_fail("������ҡҡͷ������ȥ��������������\n");
        who->set("liyiru/kill_jiaolong",1);
        command("bow");
        command("say �������ˡ�\n");
        return 1;
}
int accept_object(object who,object ob)
{
 int i;
 object *inv;
 if(!who->query("search_for_mujian"))
    return notify_fail("����ô�ҵ���\n");
 if(ob->query("id") != "wanju mujian")
    return notify_fail("�ⲻ������Ҫ�ģ�\n");
        who->delete("search_for_mujian");
 inv = all_inventory(this_object());
        for(i=0; i<sizeof(inv); i++)
        {
         if (inv[i]->query("id")=="shuizhu" || inv[i]->query("id")=="shui lingzhu")
                {
                   inv[i]->move(who);
                   message_vision("$N�ӻ����ͳ�һ�Ű�ɫ�����ӣ��ݵ�$n���\n",this_object(),who);
            message("channel:rumor",RED+"��ҥ�ԡ�ĳ�ˣ�"+who->query("name")+"�õ�ˮ�����ˣ�\n"+NOR,users());
       break;
         }
        }
  return 1;
}
void check_player ()
{
  object who = this_player();
  object me = this_object();
  if (who && visible(who))
  {
   if ( environment(who)==environment(me))
   {
    if(who->query("search_for_mujian"))
       message_vision("$N��$n˵������Ҫ�������ľ����\n",me,who);
    if (who->query("liyiru/killed_jiaolong"))
                {
                message_vision ("$N��$n˵������л��λ"+RANK_D->query_respect
(who)+
                    "��\n",me,who);
                message_vision ("$N��$n˵���������������鷳�������һ�¸��׸�
�ҵ�ľ����\n",me,who);
who->delete("liyiru/killed_jiaolong");
                who->set("search_for_mujian",1);
                }
        }
  }
}
