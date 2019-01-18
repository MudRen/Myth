//questnpc.c
//created by kuku@sjsh  2002/11

inherit NPC; 
object owner() {return query("owner");}  
string *dirs1 = ({ 
        "/d/qujing/baotou",   
        "/d/qujing/baoxiang",   
        "/d/qujing/biqiu",  
        "/d/qujing/chechi",  
        "/d/qujing/dudi",  
        "/d/qujing/fengxian",  
        "/d/qujing/firemount",  
        "/d/qujing/jilei",  
        "/d/qujing/jindou",  
        "/d/qujing/jinping",  
        "/d/qujing/jisaiguo",  
        "/d/qujing/maoying",  
        "/d/qujing/nuerguo",  
        "/d/qujing/pingding",  
        "/d/qujing/pansi",  
        "/d/qujing/tongtian",  
        "/d/qujing/qilin",  
        "/d/qujing/qinfa",  
        "/d/qujing/qinglong",  
        "/d/qujing/tianzhu",  
        "/d/qujing/wudidong",  
        "/d/qujing/wuji",  
        "/d/qujing/xiaoxitian",  
        "/d/qujing/yinwu",  
        "/d/qujing/yuhua",  
        "/d/qujing/zhujie",  
        "/d/qujing/zhuzi",  
        "/d/gao", 
        "/d/lingtai", 
        "/d/nanhai", 
        "/d/sea", 
        "/d/moon", 
        "/d/xueshan", 
}); 
         
int random_place(object me, string* dirs);  
int ask_quest (); 
int ask_finish();
         
void create() 
{ 
         mapping name;  
        if (random(2)==1){  
                name = __DIR__"random_name"->man_name();  
                set_name(name["name"],({name["id"]}));  
                set("gender", "����" );//�Ա��������Ӧ  
        }  
        else {  
                name = __DIR__"random_name"->woman_name();  
                set_name(name["name"],({name["id"]}));  
                set("gender", "Ů��" );//�Ա��������Ӧ  
        }  
        set("age",25+random(30));  
        set("attitude", "peaceful");  
        set("quest_npc",1);  
        set("str", 25);  
        set("con", 30);  
        set("int", 30);  
        set("per", 15+random(17));  
        set("combat_exp",1000000);   
        set("chat_chance", 5);  
        set("chat_msg", ({  
                (: random_move :)  
        }) );  
        set("inquiry", ([ 
                "Ѱ��" : (: ask_quest :), 
                "���": (: ask_finish :),
        ]) ); 
        setup();  
        call_out("destruct_me",900);
}  

int random_place(object me, string* dirs) 
{ 
         int  i, j, k;  
        object  newob;  
        mixed*  file, exit;  
                 
        if( !sizeof(dirs) )  return 0;  
        i = random(sizeof(dirs));    // pick up one directory  
        file = get_dir( dirs[i]+"/*.c", -1 );  
        if( !sizeof(file) )  return 0;  
        for(k=0;k<30;k++) { // try 30 times  
                j = random(sizeof(file));  
                if( file[j][1] > 0 ) {  
                        newob=load_object(dirs[i]+"/"+file[j][0]);  
                        if (newob) {    
                                if(!(exit=newob->query("exits")) ||  sizeof(exit)<1 )  
                                        continue;  
                                if(me->move(newob)) {  
                                        message_vision("$N���˹�����\n",me);  
                                        return 1;  
                                }  
                        }  
                }  
        }  
        return 0;  
} 

string invocation(object me) 
{ 
         object person,env;          
        string *dirs, where;  
        dirs=dirs1;  
        person=this_object();  
        person->set("title",me->query("name")+"Ѱ�ҵ�");  
        set("owner", me);               
        if(!random_place(person, dirs))  return "û���ڡ�";  
        env=environment(person);  
        where=person->query("name");  
        if(env)  
                where += "��"+MISC_D->find_place(env);  
                return where;  
} 
                 
void destruct_me()
{ 
        destruct (this_object());
} 

void die () 
{ 
        object me = this_object();  
        object where = environment (me);  
        destruct (me);  
        return; 
} 
                  
void unconcious() 
{ 
        die();  
} 

int ask_quest () 
{  
        mapping task; 
        object me,person; 
        me=this_player();
        person=this_object();
        if ( !me->query("task/name")||!me->query("task/id") ) { 
                command("say �Ҳ�֪����˵�����顣 \n");
                return 1;
        }
        if (!person->query("owner") || person->query("owner")!=me){
                command("say ��ҪϹ�ʣ� \n"); 
                command("kok "+me->query("id") );
                return 1;
        }
        if(me->query("task_give")){
                command("say ��Ȼ���Ѿ�������ҽ�����������Ǿ����һ㱨�ɡ� \n");
                return 1;
        }
        if (me->query("quest_ask")&&!me->query("task_give")){
                command("say �����Ѿ����������𣿻�����ȥ�� \n"); 
                return 1;
        }
        task = __DIR__"tlist"->query_task();  
        command("consider");
        command("say ��λ"+ RANK_D->query_respect(this_player()) + ",����̸�����������ɡ�������ҵ���"+task["task"]+"��,������\n"
"�������������Ȼ�����������֪�����ҾͰ����ҵĶ������㡣 \n");
        me->set("quest_ask",1); 
        return 1;
}
        
int ask_finish ()
{     
        int j,k;
        object me,person,ob;
        mixed* file;
        me=this_player();
        person=this_object();
        if (me->query("quest_ask")&&!me->query("task_give")){
                command("hmm");
                command("say �Ҹ��������û����ء� \n");             
                return 1;
        }
        if (!me->query("quest_ask")){
                command("say û���鲻�û㱨���� \n");
                return 1;
        }
        if (!person->query("owner") || person->query("owner")!=me){
                command("say ��ҪϹ�ʣ� \n"); 
                command("kok "+me->query("id") );
                return 1;
        }
        if ( !me->query("task/name")||!me->query("task/id") ) { 
                command("say �Ҳ�֪����˵�����顣 \n");
                return 1;
        }
        file = get_dir("/d/quest/newtask/questobj"+"/*.c", -1 );
        if( !sizeof(file) )  return 0;
        for(k=0;k<30;k++) { 
                j = random(sizeof(file));
                if( file[j][1] > 0 ) { 
                        ob=load_object("/d/quest/newtask/questobj"+"/"+file[j][0]);
                        if (ob) {
                                if(me->query("task/name")!= ob->query("name")||me->query("task/id")!= ob->query("id"))
                                        continue;  
                                ob->move(me);
                                command("pat "+me->query("id") );
                                command("say �ɵĲ���������Ҫ�Ķ����� \n");
                                message_vision("$N����$nһ��"+ob->query("name")+"��\n", person,me);
                                destruct(person);
                                return 1;
                        }
                }
        }
        return 1; 
}
