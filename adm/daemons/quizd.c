// quiz_d.c
// writed for sanjie-lib 10-22-2002,stey


#include <ansi.h>

#define QUESTION DATA_DIR + "static/question"
inherit F_DBASE;
inherit F_SAVE;



string random_add(string strn)
{
        string *ran_s,str;
        int i,j,k;
        str="";
        ran_s=({"��","��","��","��","��","��",});

        k=random(sizeof(ran_s));
         j=strlen(strn);

         if(j<8) return strn;
         for(i=0;i<j;i+=2){

        if (strn[i] < 176 || strn[i] > 247)  { str +=strn[i..i+1];continue;}
        if (strn[i+1] < 161 || strn[i] > 254) { str +=strn[i..i+1];continue;}
        if (strn[i] == 215 && strn[i+1] > 249) {str +=strn[i..i+1];continue;}
           if(random(100)<20)
           str +=ran_s[k]+strn[i..i+1];
           else str +=strn[i..i+1];

        }

        return str;
}
mapping *quiz = ({});

void add_translate( string key, string chinz );
void remove_translate( string key );

void create()
{
        seteuid(ROOT_UID);
        restore();
}

void remove() { save(); }

string query_save_file() { return QUESTION; }



int sizeof_quiz()
{
        return sizeof(quiz);

}
void add_quiz(mapping pattern )
{
        quiz += ({pattern});
        save();
}


void set_quiz( int i,mapping pattern)
{         quiz -=({quiz[i]}); quiz +=({pattern});
        save();
}
void delete_quiz( int i)
{
        quiz -=({ quiz[i]});
        save();
}
void dump_quiz()
{
        string  str;
        mapping q;
        int i;

        str = "";

        for(i=0; i<sizeof(quiz); i++)
                {
                        q=quiz[i];
                        str +="QUIZ NO."+i+" :"+"type: "+q["type"]+"answer: "+q["answer"]+"\n";
                        str +="QUIZ NO."+i+" :"+"Data: "+q["data"]+"\n";
                }
        write_file("/QUIZ_DUMP", str);
}



mapping query_quiz(int i)
{

        mapping def;

        if (i<0 || i > sizeof(quiz))
        return 0;
        def=quiz[i];
        if (mapp(def)) return def;
        return def;

}

/**start to ask question**/

string comfirm_answers(object obj,object victim,string answers)
{
        string str,qqn,name;
        int i;

        if(obj->query("question")!="on")
                return obj->name()+"����ûʲô���ʣ���\n";

// add by mudring.
        if(obj->query("question")=="done")
                return obj->name()+"�������Ѿ�����ˣ���\n";

        name=obj->query("quiz/q_name");

        if(victim->query("id")!=obj->query("quiz/id"))
           return name+"˵���������Ĳ�����������ȴ���ˣ�\n";

         if((int)obj->query("quiz/time")+900 < time())
           return name+"�Ѿ���ʧ�ˡ�\n";

         if(answers==obj->query("quiz/answer"))
         {
                i=victim->query("quiz_num")+1;
                str=name+"��ϲ�����ˣ���Ŀǰ�Ѿ���ȷ�ش���"+i+"���⣡��������뵽��������\n";
                if (i % 35 == 0)
                 {
                      i = i % 35 + 1;
                        i=200000+i*50;
                  victim->add("quiz_combat_exp",i);
                  victim->add("quiz_daoxing",i);
                  victim->add("quiz_potential",i/9);
                  victim->add("quiz_balance",1000000);
                  str +=name+"������"+i+"����ѧ��"+i+"����к�"+i/9+"��Ǳ�� ��100���ƽ��Ѱ���������У���\n";
                  str +=name+"�����㣺����뵽���������������ĵ���\n";
                }
                str +=name+"����"+obj->name()+"��ͷ����ʧ��!"+obj->name()+"���ڽ���ɻ���!\n";
                obj->set("question","done");
// added by mudring
                return str;
          }else
          {
                str=obj->query("quiz/str");
                str+="\n"+name+"Ц��ҡ��ҡͷ˵������Ŭ��Ӵ��\n";
                return str;
          }
}
//������㲿��
mapping random_jisuan()
{
        int j,l,k,m,n;
        mapping question,jisuan;
        string *fff;
        string name,str,strddd,strcc,ans;

        
jisuan=([
"��":({"����","��","����","�ټ�",}),
"��":({"��ȥ","����",}),
"��":({"�Ľ������","�ļ���������",}),
"ƽ��":({"�ļ�������ƽ��","�Ľ���Ķ��η�",}),
"���":({"���������ʲô��","����ʲô","������ĳ�����","����������ڣ�","�Ƕ��٣�","���ǣ�","Ϊ���٣�",}),
"λ��":({"��λ��","ʮλ��","��λ��","ǧλ��","��λ��","ʮ��λ��","����λ��","ǧʮ��λ��","��λ��","ʮ��λ��",}),
]);     
        
        
        j=random(2)+2;
        l=random(50)+1;
        strcc=chinese_number(l);
       
        for(k=0;k<j;k++)
        {
                switch(random(15))
                    {
                        case 0:
                        case 1:
                        case 2:
                        case 3:
                               m=random(20)+1;
                               l +=m;
                               fff=jisuan["��"];
                               strcc +=fff[random(sizeof(fff))]+chinese_number(m);
                               break;
                        case 4:
                        case 5:
                        case 6:
                        case 7:
                        case 8:
                                m=random(20)+1;
                                l -=m;
                                fff=jisuan["��"];
                               strcc +=fff[random(sizeof(fff))]+chinese_number(m);
                               break;
                        case 9:
                        case 10:
                        case 11:
                        case 12:
                                m=random(12)+1;
                                l *=m;
                                fff=jisuan["��"];
                               strcc +=fff[random(sizeof(fff))]+chinese_number(m);
                               break;
                        case 13:
                        case 14:

                                l =l*l;
                                fff=jisuan["ƽ��"];
                                strcc +=fff[random(sizeof(fff))];
                               break;
                        }
                }

/*
       if(random(20)>5 && l >2)
                {
                  n=random(4)+1;
                  ans=""+l;
                  n=random(strlen(ans));
                  if (n>8) n=8;
                  ans=ans[n..n];
                  fff=jisuan["λ��"];
                  strcc +="�����Ľ����"+fff[n];
          
                  }else ans=""+l;
*/
                 ans=""+l;
        

        fff=jisuan["���"];
        strcc +=fff[random(sizeof(fff))];
         
//        strddd=random_add(strcc);
        question=([]);
        
                  question["type"]="���������";
                  question["data"]= strcc;
                  question["answer"]=ans;
                  
                  return question;

}

//�����ⲿ��

mapping random_ask_question()
{
        int i,j,k,m,n,rs;
        mapping question,quesss;
        string *ran_s,*breaks_str;
        string strddd,ans,ge,type;
        
        i=random(sizeof(quiz));
        question = quiz[i];
        
        ran_s=({"��","��","��","��","��","��",});
        breaks_str=({"�ֿ�","���","�ָ�",});
        if(random(100)<3)
         {

                strddd=question["data"];
                ans=question["answer"];

          }else{
                n=random(4)+1;
                rs=random(sizeof(ran_s));
                

                switch(random(4))
                        {
                        case 0:
                             strddd=question["data"]+"��ע�⣡��Ѵ���һ���ո�����������"+chinese_number(n+1)+"�Σ�";
                             ge=" ";
                             break;
                        case 1:
                             rs=random(sizeof(ran_s));
                             if(random(2)==0)
                             {strddd=question["data"]+"���Ǻǣ����㽫������ճ��һ��"+chinese_number(n+1)+"�β���һ���ո�����";
                             ge=" ";}
                             else {
                                strddd=question["data"]+"���Ǻǣ����㽫������ճ��һ��"+chinese_number(n+1)+"�β���"+ran_s[rs]+breaks_str[random(3)]+"��";
                                ge=ran_s[rs];}
                                
                             break;                     
                        case 2:
                             strddd=question["data"]+"���Ǻǣ�ճ������������"+chinese_number(n+1)+"�Σ���Ҫ�����";
                             ge="";
                             break;                       
                        case 3:
                             strddd=question["data"]+"���Ǻǣ�����ʹ��һ��"+ran_s[rs]+breaks_str[random(3)]+",��������"+chinese_number(n+1)+"�Σ�";
                             ge=ran_s[rs];
                             break;
                          }
                          
                          
                ans=question["answer"];
                for(k=0;k<n;k++) ans +=ge+question["answer"];

                }
                 quesss=([]);
        
                  quesss["type"]  = question["type"];
                  quesss["data"]  = strddd;
                  quesss["answer"]= ans;
             
             return quesss;

}
void random_quiz(object obj,object victim)
{
        string *s_name,*f_name,*h_name,*run,*speetch,*askk;
        string name,str,strddd,ans,type;

        mapping questions;

        int i,j,k,l,m,n;
s_name=({
        "������","�ɰ���","������","���õ�","�����","��Ƥ��","���龫�ֵ�",
          });
f_name=({
        "СС","С","��","��","��","��","��","��","��",});
h_name=({
        "����","��ͷ","Ѿͷ","����","����","��ͯ","С��ʹ","����","��ͯ","��ͯ",
        });
run=({
        "",
        "ͻȻ�ܳ���",
        "��֪����ñ����"
        "Ц�������ܹ���",
        "��һ����â�߳���",
        "�ı������Ĺ���",
        "���Ժ���������",
        });
speetch=({
        "�ʵ���",
        "����˸����⣺",
        "˵�˾仰��",
        "С���ֹ��仰��",});
askk   =({
        "���������������ʲô��\n",
        "���µ�������ʲô�𰸣�\n",
        "���¿�֪���µĴ���\n",
        "��ɽ�����������\n"
        "���ܰ��ҽ�����������\n",
        "�����������ѽ������ѽ�����ܰ�����\n",});

        name=s_name[random(sizeof(s_name))]+f_name[random(sizeof(f_name))]+h_name[random(sizeof(h_name))];

        str=name+run[random(sizeof(run))]+speetch[random(sizeof(speetch))]+askk[random(sizeof(askk))];
     if(random(100)>65)
     {
       questions=random_jisuan();
        
        }
        else{
       questions=random_ask_question();
            }
         strddd=random_add(questions["data"]);
         ans=questions["answer"];
         type=questions["type"];
        str +=strddd + "\n";
        obj->set("question","on");
        obj->set("quiz/answer",ans);
        obj->set("quiz/type",type);
        obj->set("quiz/no",i);
        obj->set("quiz/id",victim->query("id"));
        obj->set("quiz/q_name",name);
        obj->set("quiz/str",strddd);
        obj->set("quiz/time",time());
        tell_object(victim,HIG+str+NOR+"\n");


}


