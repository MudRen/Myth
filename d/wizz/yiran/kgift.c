#include <ansi.h>
inherit NPC;
inherit F_SAVE;
mapping ips_res=([]);
int give_lllll();
void create()
{
         
           
         if( !restore() )
        {
                ips_res=([]);

        }
        else
        {
                if( !mapp(ips_res) ) ips_res = ([]);

        };
          set_name("ܽ�ػ�����", ({"xian zi","xian zi"}));
      set ("long", @LONG
  ���������︺�����ҷ���վ����ģ���ҸϿ���Ҫ��ask���ɡ�
LONG);
        set("gender", "Ů��");
          set("title",HIY"�����񻰼�����վ��������"NOR);
          set("age", 16);
        set("max_kee", 10000);
        set("kee", 10000);
        set("per", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("inquiry", ([           
            "�ؿ�����"  :(:give_lllll:),  
                         ]));
        setup();
        carry_object("/d/lingtai/obj/faguan")->wear();
        
}
string query_save_file()
{
        return DATA_DIR+"gift_temp";

}
int give_lllll()
{       
        object who;
        mapping skill;
        string *skillnames,*ips,ipp;
        int i;
        who=this_player();
//
        if (!userp(who)){
                command("heng");
                command("say ʲôСèС��Ҳ��Ҫ�����");
                command("qi");
                return 1;
        }
        if(who->is_busy())
           {               
            tell_object(who,"����æ���أ�\n");
                return 1;
            }
       if (this_player()->query("lll/gai") != "got" )
           {
             message_vision("$N����$n˵������վ��������������������������\n",this_object(),this_player());
           return 1;
            }     
       if (this_player()->query("lll/skills") != "got" )
           {
              message_vision("$N����$n˵������վ��������������������������\n",this_object(),this_player());
              return 1;
            }
        
         if (this_player()->query("lll/kgift") == "got" ){
               message_vision("$N����$n����һ����\n",this_object(),this_player());
               command("say ��վ����ֻ��һ�ݣ�����Ͳ����ˣ�\n");
               return 1;
                } 
          
                      ips=values(ips_res);
                      if (sizeof(ips)==0) ips=({"ddd","fff",});
                      ipp = query_ip_number(who); 
                      if ( member_array(ipp,ips) ==-1)
                      { 
                        
                        who->add("combat_exp",200000);
                        who->add("daoxing",200000);
                        who->add("force",800);
                        who->add("mana",800);
                        who->add("maximum_force",600);
                        who->add("max_mana",600);
                        who->add("max_force",600);
                        who->add("maximum_mana",600);
                        who->add("balance",500000);
                        who->set("lll/kgift","got");
                        skill=who->query_skills();
                        skillnames=keys(skill);
                        for(i=0;i<sizeof(skillnames);i++)
                        { who->set_skill(skillnames[i],101);}
                        ips_res[who->query("id")]=ipp;
                        save();
                        command("chat ��ϲ��ϲ��"+who->query("name")+"�õ��˿�վ���");
                        command("say ��ϲ��ϲ��"+who->query("name")+"�õ��˿�վ���");
                       return 1;
                      }
         
                message_vision("$N����$n����һ����\n",this_object(),this_player());
                command("say �����Ĵ��ף�����Ͳ����ˣ�\n");
       
                return 1;


}


