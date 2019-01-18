// ��˽�
// by Calvin and Leox ��ͬ����
// ��Ȩ����,δ����ɲ��÷�¼

inherit NPC;
#include <ansi.h>
inherit F_MASTER;
void create()
{
  set_name(HIC "��˽�" NOR, ({ "zhu bajie", "zhu", "bajie" }));
  set("title", HIW "����Ԫ˧" NOR);
  set("age", 600);
  set("gender", "����");
  set("long", "�ٺ٣�����������ʶ����\n");
        set("class", "tianpeng");
        create_family("����Ԫ˧��", 1, "��ʦ");
        set("rank_info/respect", "��ʦ");
  set("attitude", "peaceful");
  set("str", 50);
  set("per", 10);
  set("combat_exp", 2000000);
  set("daoxing", 2000000);

  set("max_kee", 2500);
  set("max_sen", 2500);
  set("max_force", 2500);
  set("force", 2500);
  set("force_factor", 150);
        set("mana", 2500);
        set("max_mana", 2500);  
  set("mana_factor", 150);
  set_skill("unarmed", 220);
  set_skill("dodge", 220);
  set_skill("parry", 220);
  set_skill("rake", 220);
  set_skill("force", 220);
  set_skill("spells",220);
  set_skill("skyriver-rake", 220);
  map_skill("rake", "skyriver-rake");

        set_temp("apply/damage", 50);
        set_temp("spply/armor", 50);
        set_temp("apply/dodge", 50);
       set("chat_chance_combat", 50);
       set("chat_msg_combat", ({
//                (: cast_spell, "juanbi":),
//                (: cast_spell, "tuntian" :),
//                (: perform_action, "sword", "chaofeng":),
       }) );

            setup();

  carry_object("/d/leox/weapon/pa")->wield();
  carry_object("/d/obj/armor/jinjia")->wear();
}

void attempt_apprentice(object ob)
{
        if( (string)ob->query("class")=="bonze" && (string)ob->query("gender")=="����"  )
        {
                command("kick " + ob->query("id"));
                command("say ���ߣ����ߣ���һ�������о�������\n");
                return;
        }

        if( (string)ob->query("family/family_name")=="����Ԫ˧��" ){
                if( (int)ob->query("family/generation") > 3   ){
                        command("say û���������ŵ��Ƽ����������ѿ��ǡ�\n");
                }
                else {
                        if( (int)ob->query("daoxing")+(int)ob->query("combat_exp") >= 1200000 ){
                                command("nod ");
                                command("say �ã�" + RANK_D->query_respect(ob) + "�úø��Ҹɣ��������п�Ϊ��\n");
                                command("recruit " + ob->query("id") );
                        }
                        else {
                                command("say �㻹�����������������Űɡ�\n");
                        }
                }
        }

        else{
                command("hmm");
                command("say ��λ" + RANK_D->query_respect(ob) + "������ɲ���һ���ӾͿ��Ե��ϴ�ġ�\n");
        }

        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "tianpeng");
}

void init()
{       
        object ob=this_player();

        ::init();
        if ( ((string)ob->query("gender")=="����") && ((string)ob->query("class")=="bonze") && 
(random(3) > 1) )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

        switch( random(1) ) {
                case 0:
                        command("sorry" + ob->query("id"));
                        command("say �Ҳ������պ�����ͽ����,�ϱ������Ѿ�������ˣ�");
                        break;
        }
}
