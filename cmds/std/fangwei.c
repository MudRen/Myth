#include <ansi.h>
inherit F_CLEAN_UP;
int X=20,Y=20;
int main(object me, string arg)
{
        object *obj,env;
        int pos,xx,yy,zz,c,i,ppl;
        string str,str3,strdd,strmm,struu,strme,output;

        if(me->query("kee")<40)
                return notify_fail("���������̫���ˣ�����Ϣһ�°ɣ�\n");
        me->add("kee",-20);

        env=environment(me);
        if(!env->query("hellfireroom"))
              return notify_fail("���ﲻ�����巿�䣡\n");

//      if(!arg) arg="here";

           pos=3;
           ppl=10;
        if(env->query("position_max") && (env->query("position_max") > 2 && env->query("position_max") < 8 ))
            pos=env->query("position_max");
        obj =all_inventory(env);

          for(i=0;i<sizeof(obj);i++)
         {
                     if (!obj[i]->query_temp("position"))
                      {
                        obj[i]->set_temp("position/xx",20-(pos-1)+random((2*pos)-1) );
                        obj[i]->set_temp("position/yy",20-(pos-1)+random((2*pos)-1) );
                        obj[i]->set_temp("position/zz",0);
                      }


         }

         //****//
         str=""; str3="";  strme="";strdd="";strmm="";struu="";
         for(yy=Y+(pos-1);yy>Y-(pos);yy--)
         {
                if(yy!=Y-(pos-1) || yy !=Y+(pos-1))
                str3+="����";

                ////
                str+=HIW"��"NOR;
                for(xx=X-(pos-1);xx<X+pos;xx++)
                {
                         c=0;
                        if(me->query_temp("position/xx")==xx
                                    && me->query_temp("position/yy")==yy)
                         {
                                str +=BLINK HIR "YOU "NOR;
                                strme="���  (���귽λ)X:"+(xx-X)+",Y:"+(yy-Y)+"  :"
                                       +me->name()+"("+me->query("id")+")\n";
                                obj -=({ me });
                                c=2;
                          }
                        if(sizeof(obj)==0 && c!=2 ){ str +=BBLU HIG" xx "NOR; continue; }


                        
                        //
                        for(i=0;i<sizeof(obj);i++)
                        {
                                if(!obj[i]->query("name")|| !obj[i]->query("id"))
                                {
                                        str +=BBLU HIG" xx "NOR;
                                        continue;
                                }

                                if(obj[i]->query_temp("position/xx")==xx
                                    && obj[i]->query_temp("position/yy")==yy)
                                 {
                                        ppl++;c++;
                                        zz=obj[i]->query_temp("position/zz");


                                        if(c ==1) str +=BBLU HIY"MO"+ppl+NOR;
                                        switch(zz)
                                             {
                                             case 0:
                                                    strdd +="MO"+ppl+"  (���귽λ)X:"+(xx-X)+",Y:"+(yy-Y)+"  :"
                                                    +obj[i]->name()+"("+obj[i]->query("id")+")\n";
                                                    break;
                                             case 1:
                                                    strmm +="MO"+ppl+"  (���귽λ)X:"+(xx-X)+",Y:"+(yy-Y)+"  :"
                                                    +obj[i]->name()+"("+obj[i]->query("id")+")\n";
                                                    break;
                                             case 2:
                                                    struu +="MO"+ppl+"  (���귽λ)X:"+(xx-X)+",Y:"+(yy-Y)+"  :"
                                                    +obj[i]->name()+"("+obj[i]->query("id")+")\n";
                                                    break;
                                              }
                                   }
                             }
                             //
                             if(c==0) str +=BBLU HIG" xx "NOR;


                      }////
                      str+=HIW"��\n"NOR;
              }
                //****//
        output  = HIW"����"+str3+"��\n"NOR+str+HIW"����"+str3+"��\n"NOR+strme;
        if (strdd!="") output += "����:\n"+strdd;
        if (strmm!="") output += "����:\n"+strmm;
        if (struu!="") output += "����:\n"+struu;
      write(output+"\n");
      return 1;
}

int help()
{
        write(@HELP
        ��ʱ���䷽λͼ v1.0 (Write By stey 200/12/08)
        �����÷���fangwei
        ���ӣ�
������������������������������������������
���������� xx  xx  xx  xx  xx  xx  xx ��
���������� xx  xx  xx  xx MO11 xx  xx ��
���������� xx  xx YOU  xx  xx  xx  xx ��
���������� xx  xx  xx  xx  xx  xx  xx ��(�����м��xx����ΪX:0,Y:0)
���������� xx  xx MO12 xx  xx  xx  xx ��
���������� xx  xx  xx  xx  xx  xx  xx ��
���������� xx  xx  xx  xx  xx  xx  xx ��
������������������������������������������
���  (���귽λ)X:-1,Y:1  :�����һ�(stey)
����:
MO11  (���귽λ)X:1,Y:2  :��צëͷ(four claw bad-kid)
MO12  (���귽λ)X:-1,Y:-1  :С������(small feet bat)

ע�ͣ�
�������ϵ�ͼ��xx:��ʾ�����ÿ����λ���߷��顣YOU��ʾ���ڷ���������λ�ã�MO11,MO12,
��ʾ�ֻ�����Ʒ�����ڵķ�λ����������ߵ�MO12����ǰ����gogogo south;gogogo sooth;
��������ߵ��ֵ���ǰ������뵽MO11��ǰ���������߷���һ��gogogo northeast;gogogo east;
����gogogo north;gogogo east,gogogo east����������й̶���λ������east���ھ���
���䷽λͼ���ұ��м�ķ�λ���������gogogoָ���ߵ������ʹ��gogoָ���ȥ�������
(gogoʵ�ʾ���goָ��,Ŀǰ����gogoָ��Ժ����goָ��)��������ָ���Ƿ����ҿ��ģ�
��ǰ����������ƽ�������͹�����һ���򵥵����巽λ��һ����ڿ��еģ������Ϻ͵����ϣ���
��Һ���Ʒ�����ڵ����ϣ�ע�ⲻͬ����ķ�λ�����һ���߲����ģ�����ʹ�ý�ɫ��ͨ���ܵ�
���������棬����������һ��ģ����ͼ������ע����ͬ�����ʲô���Ҫ������ͼ������
��ε�����ӳ�䣡�Ժ������fangwei up;fangwei middle;fangwei stairs;���鿴���ϣ�
���У�����Ĳ����ʲô���

HELP);
        return 1;
}

