// sgzl, 99.0.15.

inherit NPC;

int test_hispai(object ob);
void give_yaopai(object ob);
string give_map(object me);
int do_yes(string arg);

void create()
  {
   set_name("��ȸ�̶�", ({"huangque shier", "shier", "huangque"}));
   set("gender", "Ů��" );
   set("age", 22);

   set("long", "��ȸ��������������ͷ�졣\n");
   set("class", "yaomo");
   set("combat_exp", 35000);
   set("daoxing", 35000);

   set("attitude", "heroism");
   create_family("��ѩɽ", 3, "����");
   set_skill("unarmed", 40);
   set_skill("yingzhaogong", 50);
   set_skill("cuixin-zhang", 50);
   set_skill("dodge", 60);
   set_skill("xiaoyaoyou", 60);
   set_skill("parry", 60);
   set_skill("sword", 60);
   set_skill("bainiao-jian", 60);
   set_skill("throwing", 80);
   set_skill("force", 61);   
   set_skill("ningxie-force", 60);
   set_skill("literate", 80);
   set_skill("spells", 70);
   set_skill("dengxian-dafa", 60);
   map_skill("spells", "dengxian-dafa");
   map_skill("force", "ningxie-force");
   map_skill("unarmed", "yingzhaogong");
   map_skill("blade", "bingpo-blade");
   map_skill("sword", "bainiao-jian");
   map_skill("parry", "bainiao-jian");

   set("max_kee", 300);
   set("max_sen", 300);
   set("force", 300);
   set("max_force", 300);
   set("mana", 300);
   set("max_mana", 300);	
   set("force_factor", 15);
   set("mana_factor", 15);


   set("inquiry", ([
	"here" : "����Ǵ�ѩɽ����\n",
	]) );


   setup();

   carry_object("/d/obj/cloth/xueshan-pao")->wear();
   carry_object("/d/obj/armor/tenjia")->wear();
   carry_object("/d/moon/obj/snow_sword")->wield();
}

void attempt_apprentice(object ob)
{
   if( (string)ob->query("family/family_name")=="��ѩɽ" )
     {
       if( (int)ob->query("family/generation") < 3  )
          command("say ���ң����ҡ��Ҹð�" + RANK_D->query_respect(ob) + "��Ϊʦ���ǡ�\n");
       else if( (int)ob->query("family/generation") ==3  )
	  command("say �����" + RANK_D->query_rude(ob) + "������ǲ�������ˣ�\n");
      else 
         {
	  command("ok");
	  command("say �ã�" + RANK_D->query_respect(ob) + "Ͷ���ҵ����£���Ҫ����������ʦ���Ļ�������ĺÿ���\n");
	  command("recruit " + ob->query("id") );
          ob->set("title", "��ѩɽ��������");
          ob->set("class", "yaomo");
   if(! ob->query_temp("get_yaopai") )  give_yaopai(ob);
	 }
     }

    else
      {
       command(":D ");
       command("say �ã�"+ RANK_D->query_respect(ob) +"���㵽�Ҵ�ѩɽ����Ѳɽ�Ŀ�ʼ���������ܳ���ͷ�ڣ�\n");
       command("recruit " + ob->query("id") );
       ob->set("title", "��ѩɽ��������");
       ob->set("class", "yaomo");
       if(! ob->query_temp("get_yaopai") )  give_yaopai(ob);
      }

  return;
}

int test_hispai(object ob)
{
    object me=this_object();
    ob=this_player();
    if( (! ob->query_temp("get_yaopai") ) && ob->query("family/master_name")=="��ӥʹ��")   
      {
      give_yaopai(ob);
      return 1;
      }
}


void give_yaopai(object ob)
{
    object yaopai;
    object me=this_object();
    ob=this_player();
    yaopai=new("/d/xueshan/obj/yaopai");
    yaopai->move(me);
    yaopai->set("long","\n  
              ��������������������
              ����������Ⱥħ������
              ��������������������

��              ��ѩɽ����������"+ob->query("name")+"\n");
    command("whisper " + ob->query("id") + " ��������������ƣ��պ��ˡ�");
    command("give yao pai to " + ob->query("id"));
    ob->set_temp("get_yaopai", 1);
    return;
}


