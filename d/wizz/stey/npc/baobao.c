//����npc
inherit F_VENDOR_SALE;


//inherit NPC;

#include <ansi.h>
//int give_xujl();
int give_wx();
int give_wx2();
int answer_me();

void create()
{
         set_name("�񱦱�", ({"baobao"}));
   set ("long", @LONG
���������︺�����ҷ���ѧ�����Ŀɰ����񱦱�����ask baobao about ������
��ask baobao about 150����1.5M������
LONG);
           set("color", HIC);
           set("gender", "����");
        set("title",HIY"���ÿɰ���"NOR);
        set("age", 28);
        set("per", 40);
        set("attitude", "peaceful");
        set("vendor_goods", ([ 
//                "ling":    "/d/obj/stey/ling.c",
                "whip":    "/d/obj/stey/yaowhip1.c",
                "hammer":    "/d/obj/stey/tianhammer.c",
               "sword":    "/d/obj/stey/sttt.c",
                "fork":    "/d/obj/stey/shenfork.c",
                "spear":    "/d/obj/stey/shenspear.c",
                "stick":    "/d/obj/stey/tianbang.c",
               "mace":    "/d/obj/stey/goldjian.c",
                "qin":    "/d/obj/stey/moqin.c",
                "blade":    "/d/obj/stey/guiblade.c",
                "staff":    "/d/obj/stey/shenstaff.c", 
                "spellsbook":    "/d/obj/book/mihou-book.c",   
                "parrybook":    "/d/obj/book/parrybook2",
//                "renshenguo":    "/d/obj/drug/renshen-guo1",
                "forcebook":    "/d/obj/book/forcebook2",
        ]) );
        set("inquiry", ([
            "����"    :(:give_wx:),
            "��ѧ����"    :(:give_wx:),
//            "��λ�ν�"    :(:give_xujl:),
            "jiangli"    :(:give_wx:),
            "150��"    :(:give_wx2:),
   ]));
        setup();
        carry_object("/d/lingtai/obj/faguan")->wear();
}
int answer_me()
{
        command("say С���ұ��㣡�ٺ� ��\n");
        return 1;
}
int give_wx()
{
        object who=this_player();
        if (!userp(who)){
                command("heng");
                  command("say ʲôСèС��Ҳ��Ҫ����?");
                command("qi");
                return 1;
        }

         if (who->query("combat_exp") < 500000 ){
                command("hammer "+who->query("id") );
                command("say ����Ŭ��Ŭ�����ܿ�����ý����ġ�");
                command("addoil "+who->query("id") );
                return 1;
         }
                  if (who->query("combat_exp") > 1500000 ){
                command("hammer "+who->query("id") );
              return 1;
              }
         if (this_player()->query("lucky/njjj") == "got" ){
         message_vision("$N����$n����һ����\n",this_object(),this_player());
                command("say ����ֻ��һ�ݣ�����Ͳ����ˣ�\n");
        return 1;
        }
        who->add("potential",10000);
        who->add("daoxing",50000);
        who->add("combat_exp",50000);
        who->set("lucky/njjj","got");
message_vision("$N����$n���ص�Ц��Ц��$n�������巢�����ҵı仯����ʱ�ε��ڵء�\n",this_object(),this_player());
        command("tell "+who->query("id")+" 
               ���Ǳ��������һ���!\n 
               �����ѧ�����������!\n 
               ��ĵ�����������ʮ��!\n ");
log_file("baobao","["+ctime(time())+"] "+sprintf("%s(%s)��ѧ����50�򣬸��轱����\n", 
who->query("name"),who->query("id"))); 
      message_system("��ϲ����ϲ��"+HIY""+who->query("name")+""+HIW"�õ�����ѧ������ʮ��Ľ�����"); 
        return 1;
}

int give_xujl()
{
        object who=this_player();
        if (!userp(who)){
                command("heng");
                  command("say ʲôСèС��Ҳ��Ҫ����?");
                command("qi");
                return 1;
        }

         if (who->query("office_number") < 2820 ){
                command("slapslap "+who->query("id") );
                command("say ƭ��!!!");
                command("addoil "+who->query("id") );
                return 1;
         }
         if (this_player()->query("xujl") > 0 ){
         message_vision("$N����$n����һ����\n",this_object(),this_player());
                command("say ����ֻ��һ�ݣ�����Ͳ����ˣ�\n");
        return 1;
        }
        who->add("potential",500000);
    who->add("balance",15000000);
        who->add("daoxing",500000);
        who->set("xujl",1);
log_file("baobao","["+ctime(time())+"] "+sprintf("%s(%s)���˸�����������\n", who->query("name"),who->query("id"))); 
message_vision("$N����$n���е�Ц��Ц��$n����Ǯׯ����Ĵ���ƺ����˺ܶ࣬�ٿ���hpŶ...\n",this_object(),this_player());
        command("tell "+who->query("id")+" 
        �����ڴ��������һǧ������ƽ𣬵�����������꣬Ǳ��������ʮ��㡣\n");
          command("rumor ��ϲ��ϲ��"+who->query("name")+"�Ĺ�λ����λ�ӡ︨���������ν���");
          command("chat ��ϲ��ϲ��"+who->query("name")+"�Ĺ�λ����λ�ӡ�����������������ν���");
        return 1;
}

int give_wx2()
{
        object who=this_player();
        if (!userp(who)){
                command("heng");
                  command("say ʲôСèС��Ҳ��Ҫ����?");
                command("qi");
                return 1;
        }

         if (who->query("combat_exp") < 1500000 ){
                command("hammer "+who->query("id") );
                command("say ����Ŭ��Ŭ�����ܿ�����ý����ġ�");
                command("addoil "+who->query("id") );
                return 1;
         }
        if (who->query("level") < 40 ){  
            command("say ��ĵȼ�������ȥ�����������ɡ�"); 
            return 1; 
        }
         if (who->query("combat_exp") > 1900000 ){
                command("hammer "+who->query("id") );
                command("say �㶼��ô����������Ҫ��̰�ģ���");
                command("kick "+who->query("id") );
                return 1;
         }
         if (who->query("lucky/jjjjk")=="got") {
         message_vision("$N����$n����һ����\n",this_object(),this_player());
                command("say ����ֻ��һ�ݣ�����Ͳ����ˣ�����������\n");
        return 1;
        }
        who->add("potential",50000);
        who->add("daoxing",300000);
        who->add("combat_exp",1500000);  
        who->add("balance",15000000); 
        who->set("lucky/jjjjk","got");
message_vision("$N����$n���ص�Ц��Ц��$n�������巢�����ҵı仯����ʱ�ε��ڵء�\n",this_object(),this_player());
        command("tell "+who->query("id")+" 
               ���Ǳ�������������!\n 
            ��ĵ���������������!\n
            �����ѧ������һ����ʮ���!\n
            ��Ĵ��������һǧ��ٽ�!\n "); 
//          command("chat ��ϲ��ϲ��"+who->query("name")+"��ѧ����150�򣬸��轱����");
      message_system("��ϲ����ϲ��"+HIY""+who->query("name")+""+HIW"�õ�����ѧ����"+HIG"һ����ʮ��"+HIW"�Ľ�����"); 
log_file("baobao","["+ctime(time())+"] "+sprintf("%s(%s)����һ����ʮ������\n", who->query("name"),who->query("id"))); 
        return 1;
}
/*
void init()
{
     call_out("greeting", 1, this_player());
      ::init();
   add_action("do_vendor_list", "list");
} 
*/
void init()                            
{                                      
// 	call_out("greeting", 1, this_player());
//   	::init();
        add_action("do_vendor_list", "list");   	
        add_action("do_fight", "fight");     
        add_action("do_kill", "kill");       
        add_action("do_cast", "cast");       
        add_action("do_bian","bian");        
        add_action("do_cast", "perform");                           
        add_action("do_steal", "steal");       

}                                            
                                             
int do_kill(string arg)                                                       
{                                                                             
        object who = this_player();                                           
        object me = this_object();                                            
                                                                              
        if(!arg || present(arg,environment(me))!=me) return 0;                
                                                                              
        message_vision("$N��$n��в�������ɱ�ң�������ˣ�\n", me, who);    
        return 1;                                                             
}

int do_bian(string arg)                                                                                                                              
{                                                                        
        object who = this_player();                                      
        object me = this_object();                                       
                                                                         
        if(!arg || present(arg,environment(me))!=me) return 0;           
                                                                         
        message_vision("$N�ٺټ�Ц�˼���������С�����ޣ�\n", me);
        return 1;                                                        
}
                       
int do_cast(string arg)                                                                                                                                                         
{                                                                                                      
        object who = this_player();                                                                    
        object me = this_object(); 
//         if(!arg || present(arg,environment(me))!=me) return 0;                                                                      
        message_vision("$N��$n��в�������ɱ��ʦ��������ˣ�\n", me, who);                             
        return 1;                                                                                      
}
int do_steal(string arg)
{
  object who = this_player();
  object me=this_object();

  //if(!arg || present(arg,environment(me))!=me) return 0;

  message_vision ("$NͻȻ��$nЦ��������ͬ�����ˣ��α��أ�\n",me,who);
  message_vision ("$N�������鱩¶���ŵý������˻�ȥ��\n",who);
  return 1;
}
                                                                             
                                                                                                                                                                                       
int do_fight(string arg)                                                                                                            
{                                                                                                                                   
        object who = this_player();                                                                                                 
        object me = this_object();                                                                                                  
                                                                                                                                    
        if(!arg || present(arg,environment(me))!=me) return 0;                                                                      
                                                                                                                                    
        message_vision("$N��$nҡ��ҡͷ���㲻���Ҷ��֣�����\n", me, who);                                                      
        return 1;                                                                                                                   
}                 
void die()
{
  if (environment())
    message("sound", "\n\n�񱦱�������Цһ�����һ����ٻ����ģ�\n\n", environment());

  set("eff_kee", 1000);
  set("eff_gin", 1000);
  set("eff_sen", 1000);
  set("kee", 1000);
  set("gin", 1000);
  set("sen", 1000);
  set("force", 1000);
  set("mana", 1000);
}

void unconcious()
{
  die ();
}
