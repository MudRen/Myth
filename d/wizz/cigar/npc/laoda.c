//cigar �ֻ�ת��NPC 
 
#include <ansi.h> 
inherit NPC; 
string ask_for_leave(); 
 
void create() 
{ 
        set_name(HIW"ת���ֻ�����"NOR, ({"lunhui pusa","pusa"})); 
        set("gender", "Ů��" ); 
        set("age", 25); 
        set("title",HIY"����������翣��ա��ޡ���"NOR); 
        set("long", HIG"\n\n������������ƹ�ת���ֻصĴ��ǡ���������\n\n"NOR); 
        set("combat_exp", 1000000000); 
          set("daoxing", 5000); 
 
        set("attitude", "peaceful"); 
        set("per", 40); 
        set("max_kee", 20000); 
        set("max_gin", 20000); 
        set("max_sen", 20000); 
        set("inquiry", ([ 
                "�ֻ�ת��" : (: ask_for_leave :), 
                "Ͷ̥" : (: ask_for_leave :), 
                ]) ); 
        setup(); 
        carry_object("/d/ourhome/obj/pink_cloth")->wear(); 
        carry_object("/d/ourhome/obj/shoes")->wear(); 
} 
 
void init() 
{ 
        add_action("do_agree", "agree"); 
} 
 
string ask_for_leave() 
{ 
        object me=this_player(); 
 
      if ((int)me->query("combat_exp") > 900000000 ) 
{ 
                command("say ���˼�ǹ����ֻ�ת�����ɶ�Ϸ��������Ѿõ��书����з��涼Ҫ������"); 
                me->set_temp("c_lunhui", 2); 
                return ("�׺�ɣ��������ң����Ը���������һ�е�һ�У��ƺ쳾�������ң���ʦ���ţ���Ը���(agree)��"); 
        } 
 
        return ("������ת���ֻ�����׺�С�ۣ��޼����¡�\n"); 
} 
 
int do_agree(string arg) 
{ 
        int i,j,level;
        mapping skill_status;
        object ob;
        string skill,obj;
        string *skills;
        
        ob=this_player();
        if(!ob->query_temp("c_lunhui")) { 
                 command("say �������������");
                 return 1;
                 }
        if(ob->query_temp("c_lunhui") > 1 ) { 
                message_vision("$N˵�������쳾�����������ֻ�ת��������һ������������\n\n", ob); 
                command("say ��Ȼ��ˣ������ھ������������������쳾֮��Բ�㳬��֮�⣡"); 
                ob->delete("betray");      //ɾ����ʦ��¼ 
                  ob->set("combat_exp",400000); 
         ob->set("daoxing",400000); 
         ob->set("maximum_mana",1500); 
         ob->set("maximum_force",1500); 
         ob->set("mud_age",0); 
         ob->set("class","lunhui");   
         ob->set("lunhui/lunhui",1);   
         
         if( (int)ob->query("potential") > (int)ob->query("learned_points")) 
                ob->add("potential", ((int)ob->query("learned_points") - (int)ob->query("potential")+20000)); 
             //ɾ����������е�ԭʼ���� 
 
         ob->set("office_number",0); 
         ob->delete("qingren"); 
         ob->delete("obstacle"); 
         ob->delete("nyj"); 
         ob->delete("mieyao"); 
         ob->delete("members_level"); 
         ob->delete("lucky"); 
         ob->delete("lll"); 
         ob->delete("liyiru"); 
         ob->delete("liwuu"); 
         ob->delete("level"); 
         ob->delete("killme_number"); 
         ob->delete("kusong"); 
         ob->delete("kill"); 
         ob->delete("jjj"); 
         ob->delete("jjjj"); 
         ob->delete("gift_adjust"); 
         ob->delete("gift"); 
         ob->delete("fabao"); 
         ob->delete("faith"); 
         ob->delete("donation"); 
         ob->delete("eat_biou"); 
         ob->delete("eat_huozao"); 
         ob->delete("eat_jiaoli"); 
         ob->delete("eat_neidan"); 
         ob->delete("dntg"); 
         ob->delete("degree"); 
         ob->delete("death"); 
         ob->delete("baohuhuaxian"); 
         ob->delete("baohu"); 
         ob->delete("bld"); 
         ob->delete("added_title"); 
         ob->delete("PKS"); 
         ob->delete("PKD"); 
         ob->delete("MKS"); 
         ob->delete("HellZhenPass"); 
         ob->delete("DIE"); 
         ob->delete("pfmjinlei"); 
         ob->delete("rebirth"); 
         ob->delete("rsg_eaten"); 
         ob->delete("rulaitask_log"); 
         ob->delete("rulaitaskjob"); 
         ob->delete("secmieyao_killedtime"); 
         ob->delete("shengao"); 
         ob->delete("shengri"); 
         ob->delete("shushan"); 
         ob->delete("soilder"); 
         ob->delete("soilder_pay"); 
         ob->delete("task_job"); 
         ob->delete("xndc"); 
         ob->delete("xndcc"); 
         ob->delete("xndf"); 
         ob->delete("xujl"); 
         ob->delete("zhailiwu_time"); 
         ob->delete("ziyougift"); 
         ob->delete("wuji_bonus"); 
 
              //��������趨ת��֮������� 
 
         ob->set("str",40); 
         ob->set("cor",40); 
         ob->set("int",30); 
         ob->set("spi",40); 
         ob->set("cps",40); 
         ob->set("per",30); 
         ob->set("con",40); 
         ob->set("kar",30); 
 
 
    // ɾ����������еĻ���skill�����skill����playerû�����Լ�Ҫ�������������ӻ����ˣ� 
               if ( (skill_status = ob->query_skills()) || sizeof(skill_status) )
                   {
                skills  = keys(skill_status);
                j = sizeof(skill_status);  
                for(i=0; i<j; i++) {
                               ob->delete_skill(skills[i]);
                                write("deleting->" + to_chinese(skills[i]) + 
                                        "(" + skills[i] + ")\n"); 
                                   }
                     }     
                                     
                   
 
                 
                ob->delete("family"); 
                ob->set("title", HIW"ת���ֻ�"+ HIY"����һ��������"NOR); 
                ob->add("lunhui_zhuanshi", 1); 
                ob->delete_temp("betray"); 
                ob->save(); 
                command("say �����ڼ���������\n"); 
                command("chat ����һ���������㡣��������̥����ʪ��������������ɫ����ɫ�������������롣���������������롣���������缰����˵��\n"); 
                command("chat ��Ӧ��ס���ġ���Ӧ��ס�Ƿ��ġ���Ӧ������ס�ġ����Թʡ�������ס��Ϊ��ס�ʡ�\n"); 
                command("chat �ֻ�ת���տյ�ȥ��������������һ�ȣ�"+ob->query("name")+"�ƺ쳾֮�������׷���Ĺ��ҷ��ֻ�ת���ˡ�\n"); 
                return 1; 
        } 
} 
 

