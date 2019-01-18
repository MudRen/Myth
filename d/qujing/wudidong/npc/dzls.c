// Created by kuku@sjsh  2003.2
// �޵׶���������npc 

inherit NPC;
int ask_book();
int ask_blade();
string book="/d/obj/book/kugu-";

void create()
{
        set_name("��������", ({"daza laoshu", "laoshu"}));
        set("age", 22);
        set("title","�޵׶�");
        set("gender", "����");
        set("int", 35);
        set("long","�����޵׶�ר�Ÿ�����͵���������������޵׶�����Ҫ����ѧϰ���������\n");
        set("attitude", "friendly");
        set("combat_exp", 40000);
        set("daoxing", 100000);
        set("max_force", 400);
        set("force", 400);
        set("force_factor", 5);
        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_skill("literate", 150);
        set("inquiry", ([   
                "book": (: ask_book :),
                "blade": (: ask_blade :),
        ]) );
        setup();
        carry_object("/d/obj/cloth/linen")->wear();
}

void init()
{
        call_out("greeting", 1, this_player());
        ::init();
}

void greeting(object who) 
{
        if( !who || environment(who) != environment() ) return;
        if( who->query("family/family_name")!= "�ݿ�ɽ�޵׶�" ) return;
        tell_object(who,"�����������ĸ����㣺��Ҫ�޵׶��ı����������пհ��ʱ�(ask laoshu about book)�Ϳݹǵ�(ask laoshu about blade)��\n");  
}

int ask_book()
{       
        object shu1,shu2,shu3;
        object me = this_player();
        object ob = this_object();
        
        if (!me->query("family") || me->query("family/family_name")!= "�ݿ�ɽ�޵׶�" ){
                write("Ҫ��Ҫ����ȼ����޵׶��ɡ�\n");
                return 1;
        }
        
        if ( present("zhang ben", me) || present("xue shu", me) ){
                write("�㲻���Ѿ��������Ҫ��\n");
                return 1;
        }
        
        if((book+"1")->in_mud() == 0){
                shu1=new(book+"1");
                shu1->move(me);
        }
        else if((book+"2")->in_mud() == 0){
                shu2=new(book+"2");
                shu2->move(me);
        }
        else if((book+"3")->in_mud() == 0){
                shu3=new(book+"3");
                shu3->move(me);
        }
 
        else{
                command("say ���������ʱ������ã����Щʱ������Ҫ�ɡ�\n");  
                return 1;
        }
                
        message_vision("$N����$nһ���հ��ʱ���\n", ob,me);
        command("pat " +me->query("id"));  
        command("say �ú�ѧϰ�ɣ��޵׶��Ĺ��Ϳ���������\n");  
        return 1;
}

int ask_blade()
{       
        object dao;
        object me = this_player();
        object ob = this_object();
        
        if (!me->query("family") || me->query("family/family_name")!= "�ݿ�ɽ�޵׶�" ){
                write("Ҫ��Ҫ����ȼ����޵׶��ɡ�\n");
                return 1;
        }
                
        if ( present("kugu dao", me) ){
                write("�㲻���Ѿ��������Ҫ��\n");
                return 1;
        }
        
        if( "/d/obj/weapon/blade/kugudao"->in_mud() == 0 ) {
                dao= new("/d/obj/weapon/blade/kugudao");
                dao->move(me);
        }
        else{
                command("say �����Ѿ����˿ݹǵ������Щʱ������Ҫ�ɡ�\n");  
                return 1;
        }
        message_vision("$N����$nһ�ѿݹǵ���\n", ob,me);
        command("pat " +me->query("id"));  
        command("say �ú�����ร��޵׶��Ĺ��Ϳ���������\n");  
        return 1;
}
