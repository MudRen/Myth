inherit NPC; 
#include <ansi.h> 
void create()
{
        set_name("����ʹ", ({"jieyin shi", "shi", "leader"}));
        set("age", 14);
        set("attitude", "peaceful");
        set("gender", "Ů��");
        set("title", "����ʹ");
        set("str", 20);
        set("int", 20);
        set("per", 30);
        set("con", 20);
        set("max_kee", 90000);
        set("kee", 90000);
        set("max_sen", 90000);
        set("sen", 90000);
        set("combat_exp", 101100000);

        set("force", 18000);
        set("max_force", 9000);
        set("force_factor", 10);
        set_skill("unarmed", 700);
        set_skill("force", 800);
        set_skill("dodge", 800);
        set_skill("parry", 900);
        set_skill("blade", 900);
        setup();

} 

void init()
{
        object ob;

        ::init();
        if( interactive(ob=this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        } 
        add_action("do_answer", "answer");} 

void greeting(object ob)
{
        if (!ob || environment(ob) != environment())
                return; 
        if( this_object()->query_temp("check_answer") ) {
                command("say �����ش�ɡ�");
                return;
         }        
         
        switch(random(4)) 
        {
        case 0 :
                say("����ʹ΢Ц������λ" + RANK_D->query_respect(ob) +
                        "�����Ȼش���һ�����⣺������ĸ�׺�����ͬʱ���գ�����Ⱦ���һ���أ�\n");  
                this_object()->set_temp("check_answer", 1);
                call_out("say_answer", 50);
                break;  
        case 1 :
                say("����ʹ΢Ц������λ" + RANK_D->query_respect(ob) +
                        "�����Ȼش���һ�����⣺�����Ķ��Ӻ�Ů��ͬʱ���գ�����Ⱦ���һ���أ�\n");
                this_object()->set_temp("check_answer", 1);
                call_out("say_answer", 50);
                break;
        case 2 :
                say("����ʹ΢Ц������λ" + RANK_D->query_respect(ob) +
                        "�����Ȼش���һ�����⣺���������Ӻ�����ͬʱ���գ�����Ⱦ���һ���أ�\n");
                this_object()->set_temp("check_answer", 1);
                call_out("say_answer", 50);
                break;
        case 3 :
                say("����ʹ΢Ц������λ" + RANK_D->query_respect(ob) +
                        "�����Ȼش���һ�����⣺���������Ѻ�����ͬʱ���գ�����Ⱦ���һ���أ�\n");
                this_object()->set_temp("check_answer", 1);
                call_out("say_answer", 50);
                break;
        }
}

void say_answer(object who)
{
        if(!who) return;
        command("smile");
        command("say ���ˣ���Ĭ���Ǵ𰸣��Ȿ����û�д𰸵����⣬һ��Ҫ�ӵ�ʱ�����ζ�����������ˣ�ȥ�ɡ�\n");   
        this_object()->delete_temp("check_answer");     
        this_player()->move("/d/quest/tulong/spirit5");
        return ;
}
   
int do_answer(string arg)
{
        if( !(this_object()->query_temp("check_answer") ) )
                return notify_fail("ʲô��\n");

        if( !arg ) return notify_fail("��˵ʲô��\n");

        message_vision("$N������һ��Ⱦȡ�" + arg + "����\n", this_player());

        if( arg == "����" || arg == "Ů��" || arg == "����" || arg == "ĸ��" || arg == "����" || arg == "����") 
        {
        switch (random(3)) 
        {
         case 0:      
                message_vision("$N�����ó�һ��·��\n", this_object());   
                this_object()->delete_temp("check_answer");
                this_player()->move("/d/quest/tulong/spirit3");
                remove_call_out("say_answer"); 
          break;
         case 1: 
                message_vision("$N�����ó�һ��·��\n", this_object());   
                this_object()->delete_temp("check_answer"); 
                this_player()->move("/d/tulong/quest/spirit4");  
                remove_call_out("say_answer");
         break;
         case 2: 
                message_vision("$N�����ó�һ��·��\n", this_object());   
                this_object()->delete_temp("check_answer"); 
                this_player()->move("/d/tulong/quest/spirit0");
                remove_call_out("say_answer");
         break;
             } 
        return 1;
      }
        command("say ������ش�\n");
        return 1;
}


