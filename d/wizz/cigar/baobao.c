//����npc
inherit F_VENDOR_SALE;


//inherit NPC;

#include <ansi.h>
int answer_me();

void create()
{
         set_name(HIW"��ѩ��"NOR, ({"bing xue er"}));
        set("long", HIM"��ѩ���ǰ����ɳ�ר�ŷ���װ������Ů�������쳣��\n"NOR);
           set("gender", "Ů��");
        set("title",HIR"��ȿɰ� Ư���ٷ�"NOR);
        set("age", 18);
        set("per", 40);
        set("attitude", "peaceful");
        set("vendor_goods", ([ 

            "tuimo jing" : "/d/wizz/cigar/zb/jing",
            "beidou armor" : "/d/wizz/cigar/zb/tianjia",
            "zibing kui" : "/d/wizz/cigar/zb/kui",
            "biluo pao" : "/d/wizz/cigar/zb/pao",
            "feitian shoes" : "/d/wizz/cigar/zb/xue",
            "tian dun" : "/d/wizz/cigar/zb/shield",
            "tiancai pifeng" : "/d/wizz/cigar/zb/pifeng",
            "yinyang ring" : "/d/wizz/cigar/zb/jiezhi",
            "qilin wan" : "/d/wizz/cigar/zb/wan",
            "tianguang lian" : "/d/wizz/cigar/zb/necklace",
        ]) );

        setup();
        carry_object("/d/moon/obj/luoyi.c")->wear();
}
int answer_me()
{
        command("say С���ұ��㣡�ٺ� ��\n");
        return 1;
}



void init()                            
{                                      
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
