//Creat by waiwai@2001/05/19

inherit NPC;
#include <ansi.h>
int promote_me(object ob);

void create()
{
        set_name(HIR"���ӽ�"NOR, ({ "shangshu","yu" }));
	set("title", HIY "��͢һƷ�� ��������" NOR );
        set("gender", "����");
        set("age", 54);
        set("long",
        "���ǵ��������ߵĺ��ˣ��빬�еĹ�ϵҲ�����磬�����ƹ���\n"
		"������Ա��Ȩ,�������������λ�ã������ǽ�����Ϊ���������Ե\n"
		"�ʣ�����ս���պգ����н���ĵ�λ��\n"
		);

        set("vendetta_mark", "authority");
        set("attitude", "peaceful");
        set("str", 27);
        set("int", 25);

  set_skill("literate", 800);
  set_skill("spear", 800);
  set_skill("force", 800);
  set_skill("dodge", 800);
  set_skill("parry", 800);
  set_skill("mace", 800);
  set_skill("archery", 800);
  set_skill("wusi-mace", 800);
  set_skill("yanxing-steps", 800);
  set_skill("bawang-qiang", 800);
  set_skill("lengquan-force", 800);
  set_skill("unarmed", 800);
  set_skill("changquan", 800);
  set_skill("spells", 800);
  set_skill("baguazhou", 800);
  map_skill("spells", "baguazhou");

  map_skill("mace", "wusi-mace");
  map_skill("force", "lengquan-force");
  map_skill("unarmed", "changquan");
  map_skill("spear", "bawang-qiang");
  map_skill("parry", "bawang-qiang");
  map_skill("dodge", "yanxing-steps");
  set("max_sen", 6000);
  set("max_kee", 6000);
  set("force", 6000);
  set("max_force", 6000);
  set("force_factor", 300);
  set("mana", 6000);
  set("max_mana", 6000);
  set("mana_factor", 300);
        set("rank",1);
	 create_family("��͢", 5, "����");
        set("class", "officer");

        set("office_number", 6000);

	set("inquiry", ([
            "�ӹٽ���" :  (: promote_me :),
             "����" : (: promote_me :),]) );

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
            (: command ("alert") :),
            (: command ("alert") :),
            (: command ("alert") :),
	(: perform_action, "mace", "jianshen" :),
                        }) );

        setup();

  carry_object("/d/obj/armor/tiejia")->wear();
  carry_object("/d/obj/weapon/mace/copperjian")->wield();
}

int promote_me(object ob)
{
	int exp,mpzc;
       ob=this_player();

if(ob->query("family/family_name") == "���ƽ�����")
		{
		exp=ob->query("combat_exp");
		mpzc=ob->query("mpzc");	
		if(exp<250000)
			{
			command("say ��ƾ�㣿���С���;������٣��������룡����");				
			return 1;
		    }
		if(ob->query_temp("ASK_TO_RISE")<1)
			{
			ob->set_temp("ASK_TO_RISE",1);
			}
		else
			{
			command("say ���ϸո�ȥ���ˣ���һ��ʱ����������");
			return 1;
			}
	    if(exp>=250000&&exp<500000)
			{
			command("say �ã��ã��ã��������������ϣ�Ϊ��ӹٽ���������");
			ob->set("title",HIY"���ƽ�����ƫ����"NOR);
			ob->set("rank",6);
			message("vision",HIR"���ӽ�:������ּ,�ѷ� "+ob->name()+" Ϊ "+ob->query("title")+"\n"NOR,users());	
			return 1;
			} 
	    if(exp>=500000&&exp<1000000)
			{
			command("say �ã��ã��ã��������������ϣ�Ϊ��ӹٽ���������");
			ob->set("title",HIY"���ƽ�������������"NOR);
			ob->set("rank",5);
			message("vision",HIR"���ӽ�:������ּ,�ѷ� "+ob->name()+" Ϊ "+ob->query("title")+"\n"NOR,users());	
			return 1;
			} 
	    if(exp>=1000000&&exp<1250000)
			{
			command("say �ã��ã��ã��������������ϣ�Ϊ��ӹٽ���������");
			ob->set("title",HIW"���ƽ�������²����"NOR);
			ob->set("rank",5);
			message("vision",HIR"���ӽ�:������ּ,�ѷ� "+ob->name()+" Ϊ "+ob->query("title")+"\n"NOR,users());	
			return 1;
			} 
	    if(exp>=1250000&&exp<1500000)
			{
			command("say �ã��ã��ã��������������ϣ�Ϊ��ӹٽ���������");
			ob->set("title",HIW"���ƽ��������ܽ���"NOR);
			ob->set("rank",5);
			message("vision",HIR"���ӽ�:������ּ,�ѷ� "+ob->name()+" Ϊ "+ob->query("title")+"\n"NOR,users());	
			return 1;
			} 
	    if(exp>=1500000&&exp<1750000)
			{
			command("say �ã��ã��ã��������������ϣ�Ϊ��ӹٽ���������");
			ob->set("title",HIW"���ƽ�������������"NOR);
			ob->set("rank",4);
			message("vision",HIR"���ӽ�:������ּ,�ѷ� "+ob->name()+" Ϊ "+ob->query("title")+"\n"NOR,users());	
			return 1;
			} 
	    if(exp>=1750000&&exp<2000000)
			{
			command("say �ã��ã��ã��������������ϣ�Ϊ��ӹٽ���������");
			ob->set("title",HIG"���ƽ�������������"NOR);
			ob->set("rank",4);
			message("vision",HIR"���ӽ�:������ּ,�ѷ� "+ob->name()+" Ϊ "+ob->query("title")+"\n"NOR,users());	
			return 1;
			} 
	    if(exp>=2000000&&exp<2250000)
			{
			command("say �ã��ã��ã��������������ϣ�Ϊ��ӹٽ���������");
			ob->set("title",HIG"���ƽ�������²����"NOR);
			ob->set("rank",4);
			message("vision",HIR"���ӽ�:������ּ,�ѷ� "+ob->name()+" Ϊ "+ob->query("title")+"\n"NOR,users());	
			return 1;
			} 
	    if(exp>=2250000&&exp<2500000)
			{
			command("say �ã��ã��ã��������������ϣ�Ϊ��ӹٽ���������");
			ob->set("title",HIG"���ƽ������󽫾�"NOR);
			ob->set("rank",3);
			message("vision",HIR"���ӽ�:������ּ,�ѷ� "+ob->name()+" Ϊ "+ob->query("title")+"\n"NOR,users());	
			return 1;
			} 
	    if(exp>=2500000&&exp<2750000)
			{
			command("say �ã��ã��ã��������������ϣ�Ϊ��ӹٽ���������");
			ob->set("title",HIB"���ƽ�����ƽ������"NOR);
			ob->set("rank",3);
			message("vision",HIR"���ӽ�:������ּ,�ѷ� "+ob->name()+" Ϊ "+ob->query("title")+"\n"NOR,users());	
			return 1;
			} 
	    if(exp>=2750000&&exp<3000000)
			{
			command("say �ã��ã��ã��������������ϣ�Ϊ��ӹٽ���������");
			ob->set("title",HIB"���ƽ�������������"NOR);
			ob->set("rank",3);
			message("vision",HIR"���ӽ�:������ּ,�ѷ� "+ob->name()+" Ϊ "+ob->query("title")+"\n"NOR,users());	
			return 1;
			} 
	    if(exp>=3000000&&exp<3500000)
			{
			command("say �ã��ã��ã��������������ϣ�Ϊ��ӹٽ���������");
			ob->set("title",HIC"���ƽ������򶫽���"NOR);
			ob->set("rank",2);
			message("vision",HIR"���ӽ�:������ּ,�ѷ� "+ob->name()+" Ϊ "+ob->query("title")+"\n"NOR,users());	
			return 1;
			} 
	    if(exp>=3500000&&exp<4000000)
			{
			command("say �ã��ã��ã��������������ϣ�Ϊ��ӹٽ���������");
			ob->set("title",HIC"���ƽ�������������"NOR);
			ob->set("rank",2);
			message("vision",HIR"���ӽ�:������ּ,�ѷ� "+ob->name()+" Ϊ "+ob->query("title")+"\n"NOR,users());	
			return 1;
			} 
	    if(exp>=4000000&&exp<5000000)
			{
			command("say �ã��ã��ã��������������ϣ�Ϊ��ӹٽ���������");
			ob->set("title",HIC"���ƽ�������������"NOR);
			ob->set("rank",2);
			message("vision",HIR"���ӽ�:������ּ,�ѷ� "+ob->name()+" Ϊ "+ob->query("title")+"\n"NOR,users());	
			return 1;
			} 
	    if(exp>=5000000&&exp<6000000)
			{
			command("say �ã��ã��ã��������������ϣ�Ϊ��ӹٽ���������");
			ob->set("title",HIM"���ƽ��������ｫ��"NOR);
			ob->set("rank",1);
            message("vision",HIR"���ӽ�:������ּ,�ѷ� "+ob->name()+" Ϊ "+ob->query("title")+"\n"NOR,users()); 
			return 1;
			} 
	    if(exp>=6000000&&exp<8000000)
			{
			command("say �ã��ã��ã��������������ϣ�Ϊ��ӹٽ���������");
			ob->set("title",HIM"���ƽ��������ｫ��"NOR);
			ob->set("rank",1);
			message("vision",HIR"���ӽ�:������ּ,�ѷ� "+ob->name()+" Ϊ "+ob->query("title")+"\n"NOR,users());	
			return 1;
			} 
	    if(exp>=8000000)
			{
			if(mpzc>5000&&ob->query("mark/chaotingtask")
			 &&(int)ob->query("mark/chaotingtask")>2)
				{
		       // Ұ��ɽ����ȫ�����µ�ͼ��
                	        command("say ��������!!!��λ"+RANK_D->query_respect(ob)+"�������Ի������Ĺ�����");
				command("say ����ս���������һ�������ڻ�����ǰ���Լ��䡣����");
				ob->set("title",HIW"���ƽ����������Ԫ˧"NOR);
				ob->set("rank",1);
				}
			else
				{
				command("say �ã��ã��ã��������������ϣ�Ϊ��ӹٽ���������");
				ob->set("title",HIM"���ƽ����������󽫾�"NOR);
				ob->set("rank",1);
				}
			message("vision",HIR"���ӽ�:������ּ,�ѷ� "+ob->name()+" Ϊ "+ob->query("title")+"\n"NOR,users());	
			return 1;
			} 

		}
else
		{
		command("say ����������˼���Ҳ�����ٷ��ƣ�����");
		return 1;
		}

}
void init()
{
		object ob;
		::init();
if( interactive(ob = this_player()) && !is_fighting() )
	    {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
 if((string)ob->query("family/family_name") != "���ƽ�����")
//  if( (int)ob->query("PKS")-ob->query("BCF")*2 > 15 ) 
  if( (int)ob->query("PKS") > 1 )  
	{
        command("say �ø�մ��Ѫ�ȵ���ͽ�������ڴ���Ұ������!��������!");
      	kill_ob(ob);
       }
      else {
command("say ��������ԩ�飬������ط�������!");
}
}
int accept_object(object who, object ob)
{
        object gold;
         if((string)who->query("family/family_name") == "���ƽ�����"
          && ob->query("������ͼ")=="YES"
          && this_object()->query("have_give_gold")!=1
          && ob->query("material")=="copper")
          {
          who->add("mpzc",50);
          gold=new(GOLD_OB);
          gold->set_amount(50);
          gold->move(who);
          if(who->query("mark/chaotingtask"))
	      who->add("mark/chaotingtask",1);
          else who->set("mark/chaotingtask",1);
          set("have_give_gold",1);
          call_out( "todest",1,ob );
          command("say ���˳�͢����֮������ü�������ʥ�ϣ�����ּ�⣡\n");
          return 1;
          }
           }
void todest(object ob)
{
		destruct(ob);
}

