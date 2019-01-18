// sgzl, 99.0.15.
// �������ֺ�����ĺ���������

inherit NPC;

int test_hispai(object ob);
void give_yaopai(object ob);
string give_map(object me);
int do_yes(string arg);

void create()
  {
   set_name("��ӥʹ��", ({"shenying shizhe", "shizhe", "shenying", "eagle"}));
   set("gender", "����" );
   set("age", 34);

   set("long", "��ѩɽѲɽ�ܶ�������ӥʹ�ߣ������Ĵ�Ѳ�飬�˷����硣\n");
   set("class", "yaomo");
   set("combat_exp", 80000);
   set("daoxing", 75000);

   set("attitude", "heroism");
   create_family("��ѩɽ", 3, "����");
   set_skill("unarmed", 60);
   set_skill("cuixin-zhang", 60);
   set_skill("dodge", 60);
   set_skill("xiaoyaoyou", 70);
   set_skill("parry", 60);
   set_skill("sword", 60);
   set_skill("bainiao-jian", 90);
   set_skill("force", 60);   
   set_skill("ningxie-force", 70);
   set_skill("literate", 70);
   set_skill("spells", 60);
   set_skill("dengxian-dafa", 60);
   set_skill("throwing", 30);
   map_skill("spells", "dengxian-dafa");
   map_skill("force", "ningxie-force");
   map_skill("unarmed", "yingzhaogong");
   map_skill("blade", "bingpo-blade");
   map_skill("blade", "bingpo-blade");
   map_skill("sword", "bainiao-jian");
   map_skill("parry", "bainiao-jian");

   set("max_kee", 500);
   set("max_sen", 500);
   set("force", 700);
   set("max_force", 700);
   set("mana", 700);
   set("max_mana", 700);	
   set("force_factor", 35);
   set("mana_factor", 35);


   set("inquiry", ([
	"name" : "���´�ѩɽ��ӥʹ�ߣ��кι�ɣ�\n",
	"here" : "�����أ������Ȳ������Ǵ�ѩɽ��\n",
        "����" : (: test_hispai :),
	"��ѩɽ" : (: give_map :),
	]) );

   set("no_map", 0);

   setup();

   carry_object("/d/obj/cloth/xueshan-pao")->wear();
   carry_object("/d/obj/armor/tenjia")->wear();
   carry_object("/d/gao/obj/sword")->wield();
}

void attempt_apprentice(object ob)
{
   if( (string)ob->query("family/family_name")=="��ѩɽ" )
     {
       if( (int)ob->query("family/generation") < 3  )
          command("say ���ң����ҡ��Ҹð�" + RANK_D->query_respect(ob) + "��Ϊʦ���ǡ�\n");
       else if( (int)ob->query("family/generation") ==3  )
	  command("say �����" + RANK_D->query_rude(ob) + "������ǲ��ү���ˣ�\n");
      else 
         {
	  command(":D");
	  command("say �ã�" + RANK_D->query_respect(ob) + "Ͷ���ҵ����£��������ģ������ģ�\n");
	  command("recruit " + ob->query("id") );
          ob->set("title", "��ѩɽѲɽС��");
          ob->set("class", "yaomo");
   if(! ob->query_temp("get_yaopai") )  give_yaopai(ob);
	 }
     }

    else
      {
       command(":D ");
       command("say �ã�"+ RANK_D->query_respect(ob) +"���㵽�Ҵ�ѩɽ����Ѳɽ�Ŀ�ʼ���������ܳ���ͷ�ڣ�\n");
       command("recruit " + ob->query("id") );
       ob->set("title", "��ѩɽѲɽС��");
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

��              ��ѩɽѲɽʹ�ߣ�"+ob->query("name")+"\n");
    command("whisper " + ob->query("id") + " ������Ѳɽ�����ƣ��պ��ˡ�");
    command("give yao pai to " + ob->query("id"));
    ob->set_temp("get_yaopai", 1);
    return;
}


string give_map(object me)
{
	me=this_player();
	me->set_temp("need_map", 1);
	return "��ѩɽ���ǿ��Ǹ��õط�������ȥ��(yes)��\n";
}

void init()
{
	add_action("do_yes", "yes");
}

int do_yes(string arg)
{
	object me;

	me=this_player();
	
	if(me->query_temp("need_map")) 
	{
		message_vision("$N�������ȥ��\n\n", me);
		if( query("no_map") == 0 )
		{
message_vision("��ӥʹ��˵�����ã����Ҹ���һ�ŵ�ͼ�ɣ����ñ��������ˡ�\n", me);
			me->set_temp("need_map", 0);

			carry_object("/d/obj/misc/xueshan-map");
			command("give xueshan map to " + me->query("id"));
			set("no_map", 1);
                        call_out("regenerate", 240);
		}
		else
		{
message_vision("��ӥʹ��˵�����ұ��������һ�ŵ�ͼ�ģ����Ǹղű�����������ˡ�\n", me);
		}

		return 1;
	}
	return 0;
}

int regenerate()
{
	set("no_map", 0);
	return 1;
}

