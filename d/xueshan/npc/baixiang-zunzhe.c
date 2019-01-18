
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// baixiang-zunzhe.c...weiqi, 97.09.15.

inherit NPC;
string ask_chuxian();
   string ask_cancel();
void create()
{
   set_name("��������", ({"baixiang zunzhe", "baixiang", "zunzhe"}));
   set("title", "��������");
   set("gender", "����" );
   set("age", 43);
   set("per", 112);//no rongmao description.
   set("str", 50);
   set("long", "��λ���������������Ĵ���ʿ����ǰ��ʨ��ɽ����������\nʨ��ɽ���������������ʨ��ħͶ���������������˻������ߡ�\n��ƽ���µ������󣬿�������������˾����ᡣ\n");
   set("class", "yaomo");
   set("combat_exp", 800000);
   set("attitude", "peaceful");
   create_family("��ѩɽ", 2, "����");
   set_skill("unarmed", 150);
   set_skill("cuixin-zhang", 80);
   set_skill("dodge",100);
   set_skill("xiaoyaoyou",100);
   set_skill("parry", 120);
   set_skill("blade", 110);
   set_skill("bingpo-blade", 120);
   set_skill("force",110);
   set_skill("ningxie-force",100);
   set_skill("sword", 120);
   set_skill("bainiao-jian", 110);
   set_skill("literate", 70);
   set_skill("spells",100);
   set_skill("dengxian-dafa", 80);
   map_skill("spells", "dengxian-dafa");
   map_skill("force", "ningxie-force");
   map_skill("sword", "bainiao-jian");
   map_skill("unarmed", "cuixin-zhang");
   map_skill("blade", "bingpo-blade");
   map_skill("dodge", "xiaoyaoyou");

   set("max_kee", 1200);
   set("max_sen", 600);
   set("force", 1600);
   set("max_force", 800);
   set("mana", 800);
   set("max_mana", 400);   
   set("force_factor", 60);
   set("mana_factor", 20);

        set("eff_dx", -200000);
        set("nkgain", 400);

    set("inquiry", ([
     "����" : (:ask_chuxian:),
    ]));
   setup();
   carry_object("/d/obj/armor/yinjia")->wear();
   carry_object("/d/obj/weapon/blade/yanblade")->wield();
}
string ask_cancel()
{
    object me=this_player();
if((int)me->query_temp("m_mieyao"))
{
      me->add("daoxing",-2000);
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

void attempt_apprentice(object ob)
{
   if( (int)ob->query("str") < 20 ){
     command("kick " + ob->query("id"));
     command("say ���ߣ����ߣ���һ��������������˾�������\n");
     return;
   }

   if( (string)ob->query("family/family_name")=="��ѩɽ" ){
     if( (int)ob->query("family/generation") < 2  ){
        command("say ���ң����ҡ��Ҹð�" + RANK_D->query_respect(ob) + "��Ϊʦ���ǡ�\n");
     }
     else if( (int)ob->query("family/generation") ==2  ){
        command("say �����" + RANK_D->query_rude(ob) + "������ǲ��үү���ˣ�\n");
     }
     else if( (int)ob->query("family/generation") ==3  ){
        command(":D");
        command("say �����" + RANK_D->query_rude(ob) + "�ǲ��Ǳ�ʦ���ϳ����ˣ���үү�ҽ�������ã����������...\n");
        command("recruit " + ob->query("id") );
     }
     else {
        if( (int)ob->query("combat_exp") >= 50000 ){
          command(":D ");
          command("say �ã�" + RANK_D->query_respect(ob) + "�úø��Ҹɣ���������ĺô���\n");
          command("recruit " + ob->query("id") );
        }
        else {
          command("say �㻹�������ģ���ѻ���������Űɡ�\n");
        }
     }
   }

   else{
     command("hmm");
     command("say ��λ" + RANK_D->query_respect(ob) + "���㻹�������ģ���ѻ�����������ɡ�\n");
   }

   return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "yaomo");
}

void init()
{       
   object ob=this_player();

   ::init();
   if ( ((string)ob->query("gender")=="����") && ((int)ob->query("str") < 20) && (random(3) > 1) )
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
     command("kick " + ob->query("id"));
     command("say ���������");
     command("laugh");
     break;
   }
}

string ask_chuxian()
{
   object me=this_player();
   
   if(me->query("family/family_name")!="��ѩɽ")
      return ("�㲻�Ǳ�������!");

   command("pat "+me->query("id"));
   command("say ��־����");
   return "/d/obj/mieyao"->query_yao(me);
}
 


