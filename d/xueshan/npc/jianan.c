// xunshi.c
#include <ansi.h>

inherit NPC;
int give_jiasha();

void create()
{
        set_name("����", ({"jia lan", "pusa"}));
	set("gender", "����" );
	set("age", 33);
         set("per",40);
	set("class", "yaomo");
	set("combat_exp", 25000);
  set("daoxing", 20000);

	set("attitude", "peaceful");
	create_family("��ѩɽ", 4, "����");
	set_skill("unarmed", 30);
	set_skill("yingzhaogong", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_skill("blade", 30);
	set_skill("bingpo-blade", 30);
	set_skill("xiaoyaoyou", 30);
	set_skill("force", 30);   
	set_skill("ningxie-force", 30);
	map_skill("force", "ningxie-force");
	map_skill("blade", "bingpo-blade");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("unarmed", "yingzhaogong");

	set("max_kee", 300);
	set("max_sen", 300);
	set("force", 300);
	set("max_force", 250);
	set("force_factor", 5);

	set("eff_dx", -8000);
	set("nkgain", 60);
           set("inquiry", ([ 
                 "������"  :(:give_jiasha:), 
                 "jiasha"  :(:give_jiasha:), 
                    ])); 

	setup();
	carry_object("/d/obj/cloth/xueshan-pao")->wear();
	carry_object("/d/obj/weapon/blade/iceblade")->wield();
}

int give_jiasha()  
{
      object newob,who,me;
          string fabao_id; 
     me=this_player();
     who=this_player();
      if (!userp(who)){  
      command("say ʲôСèС��Ҳ��Ҫ�����");  
      return 1;  
       }  
  if(who->is_busy()) 
            {
         tell_object(who,"����æ���أ�\n"); 


              return 1;
                         }
         if(present("jia sha",who)) 
         {  
message_vision("$N����$n����һ����\n",this_object(),this_player());  
                who->start_busy(2);
               return 1; 
                    }
              if( me->query("fo/jiasha") ) 
                     {
             newob = new("/obj/jiasha"); 
             if( newob )
                         { 
                     newob->set("owner_id", getuid(me)); 
                     if( !newob->restore() )   { 
                                     tell_object(me, "���� restore jiasha. \n"); 
                                     destruct(newob); 
                                     return 1; 
                             } 
                            fabao_id = (string)newob->query("id"); 
                           if(!fabao_id) { // mon 9/5/98 
                               destruct(newob); 
                                return 1; 
                            } 
                             seteuid(fabao_id); 
                            export_uid(newob); 
                             seteuid(getuid()); 
                              newob->save(); 
                             newob->move(me); 
                    tell_object(me,HIR"������ĸ����ˡ�\n"NOR); 
                   return 1;
             }
              else {
                    tell_object(me,HIR"���������ʱ�ò��ˣ��ȵȡ�\n"NOR); 
                        return 1;
                }
            }
                                    tell_object(me,HIR"��û���������ġ�\n"NOR); 
              return 1;
}
